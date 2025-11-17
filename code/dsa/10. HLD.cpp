ll par[N], sub_tree_sz[N], heavy[N], wt_from_parent[N], depth[N], head[N],
    position[N];
vector<pair<ll, ll>> gd[N];

// HLD part start
ll dfs(ll node, ll p) {
  par[node] = p;
  sub_tree_sz[node] = 1;
  heavy[node] = -1;

  for (auto [v, w] : gd[node]) {
    if (v == p)
      continue;
    depth[v] = depth[node] + 1;
    wt_from_parent[v] = w;
    sub_tree_sz[node] += dfs(v, node);
    if (heavy[node] == -1 || sub_tree_sz[v] > sub_tree_sz[heavy[node]]) {
      heavy[node] = v;
    }
  }
  return sub_tree_sz[node];
}
ll pos;
void decompose(ll node, ll hd) {
  head[node] = hd;
  position[node] = ++pos;
  if (heavy[node] != -1) {
    decompose(heavy[node], hd);
  }
  for (auto [v, w] : gd[node]) {
    if (v != par[node] && v != heavy[node]) {
      decompose(v, v);
    }
  }
}

// HLD part end

// in main function
ll n, m;
cin >> n;
SEGMENT_TREE seg(n); // Lazy if needed
vector<ll> edge_u(n), edge_v(n), edge_node(n);

for (int i = 1; i < n; i++) {
  ll u, v, wt = 1;
  cin >> u >> v >> wt;
  gd[u].push_back({v, wt});
  gd[v].push_back({u, wt});
  edge_u[i] = u;
  edge_v[i] = v;
}

dfs(1, -1);
pos = 0;
decompose(1, 1);

for (int i = 1; i <= n; i++) {
  // seg.v[position[i]] = val[i];  // for node value
  seg.v[position[i]] = wt_from_parent[i]; // for edge value
}

// work on a specific edge
for (int i = 1; i < n; i++) {
  ll u = edge_u[i], v = edge_v[i];
  edge_node[i] = (depth[u] > depth[v]) ? u : v;
}

seg.build(1, 1, n);

auto updatePath = [&](ll u, ll v, ll x) {
  while (head[u] != head[v]) {
    if (depth[head[u]] < depth[head[v]])
      swap(u, v);
    seg.update(1, 1, n, position[head[u]], position[u], x);
    u = par[head[u]];
  }
  if (depth[u] > depth[v])
    swap(u, v);
  // edge value
  if (u != v) {
    seg.update(1, 1, n, position[u] + 1, position[v], x);
  }
  // node value
  // seg.update(1, 1, n, position[u], position[v], x);
};

auto querypath = [&](ll u, ll v) {
  ll ans = -inf;
  while (head[u] != head[v]) {
    if (depth[head[u]] < depth[head[v]])
      swap(u, v);
    ans = max(ans, seg.query(1, 1, n, position[head[u]], position[u]));
    u = par[head[u]];
  }
  if (depth[u] > depth[v])
    swap(u, v);
  // upward + downward
  if (u != v) {
    ans = max(ans, seg.query(1, 1, n, position[u] + 1, position[v]));
  }
  // only upward
//   ans = max(ans, seg.query(1, 1, n, position[u], position[v])); // for node value
  return ans;
};

seg.update(1, 1, n, position[edge_node[s]], position[edge_node[s]], x); // single point update. if path update need call update path
cout << querypath(x, s) << '\n';
