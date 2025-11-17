// TC: O(V + ElogV)
typedef pair<ll, ll> pairi;
ll N = 20000 + 5;
vector<vector<pairi>> adj(N);
vector<ll> dis(N, inf), parent(N);

void dijkstra(ll src) {
  priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
  dis[src] = 0;
  pq.push({0, src});
  while (pq.size()) {
    auto top = pq.top();
    pq.pop();
    for (auto i : adj[top.second]) {
      ll v = i.first;
      ll wt = i.second;
      if (dis[v] > dis[top.second] + wt) {
        dis[v] = dis[top.second] + wt;
        pq.push({dis[v], v});
        parent[v] = top.second
      }
    }
  }
}
ll node = n;
while (parent[node] != node) {
  path.push_back(node);
  node = parent[node];
}
path.push_back(1);