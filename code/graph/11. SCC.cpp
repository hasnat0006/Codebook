unordered_map<ll, vector<ll>> adj, InvAdj;
stack<ll> order;
unordered_map<ll, bool> visited;
unordered_map<ll, vector<ll>> all_scc;
unordered_map<ll, ll> compId;
void dfs_for_start(ll curr) {
  visited[curr] = 1;
  for (auto i : adj[curr])
    if (!visited[i])
      dfs_for_start(i);
  order.push(curr);
}
vector<ll> curr_comp;
void dfs_for_scc(ll curr) {
  visited[curr] = 1;
  for (auto i : InvAdj[curr])
    if (!visited[i])
      dfs_for_scc(i);
  curr_comp.push_back(curr);
}
inline void scc() {
  ll n, e, u, v;
  cin >> n >> e;
  for (ll i = 0; i < e; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    InvAdj[v].push_back(u);
  }
  for (ll i = 1; i <= n; i++)
    if (!visited[i])
      dfs_for_start(i);
  visited.clear();
  while (!order.empty()) {
    if (!visited[order.top()]) {
      curr_comp.clear();
      dfs_for_scc(order.top());
      ll sz = all_scc.size() + 1;
      all_scc[sz] = curr_comp;
      for (auto i : curr_comp)
        compId[i] = sz;
    }
    order.pop();
  }
}
// no.of ways and min cost of connecting the sccs 
const ll MOD = 1e9 + 7, N = 1e5 + 2, INF = 1e18 + 2;
ll n, m, comp[N];
vector<ll> adj[N], rev[N];
bitset<N> vis;
void DFS1(ll u, stack<ll> &TS) {
  vis[u] = true;
  for (ll v : adj[u])
    if (!vis[v])
      DFS1(v, TS);
  TS.push(u);
}
void DFS2(ll u, const ll scc_no, ll &min_cost, ll &ways, vector<ll> &cost) {
  vis[u] = true;
  comp[u] = scc_no;
  for (ll v : rev[u])
    if (!vis[v]) {
      if (min_cost == cost[v])
        ++ways;
      else if (min_cost > cost[v]) {
        ways = 1;
        min_cost = cost[v];
      }
      DFS2(v, scc_no, min_cost, ways, cost);
    }
}
signed main() {
  FIO cin >> n;
  vector<ll> cost(n + 1);
  for (ll i = 1; i <= n; ++i)
    cin >> cost[i];
  cin >> m;
  while (m--) {
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    rev[v].push_back(u);
  }
  ll tot = 0, ways = 1;
  stack<ll> TS;
  for (ll i = 1; i <= n; ++i)
    if (!vis[i])
      DFS1(i, TS);
  vis.reset();
  ll scc_no = 0;
  while (!TS.empty()) {
    ll u = TS.top();
    TS.pop();
    if (!vis[u]) {
      ll tmp_cst = cost[u], tmp_ways = 1;
      DFS2(u, ++scc_no, tmp_cst, tmp_ways, cost);
      tot += tmp_cst;
      ways = (ways * tmp_ways) % MOD;
    }
  }
  cout << tot << ' ' << ways;
} // TC: O(V+E)
