vector<ll> d(n, INF);
d[s] = 0;
deque<ll> q;
q.push_front(s);
while (!q.empty()) {
  ll v = q.front();
  q.pop_front();
  for (auto edge : adj[v]) {
    ll u = edge.first;
    ll w = edge.second;
    if (d[v] + w < d[u]) {
      d[u] = d[v] + w;
      if (w == 1)
        q.push_back(u);
      else
        q.push_front(u);
    }
  }
}
