// TC : O(V.E) 
vector<ll> dist;
vector<ll> parent;
vector<vector<pair<ll, ll>>> adj;
// resize the vectors from main function

void bellmanFord(ll n, ll src) {
  dist[src] = 0;
  for (ll step = 0; step < n; step) {
    for (ll i = 1; i <= n; i++) {
      for (auto it : adj[i]) {
        ll u = i;
        ll v = it.first;
        ll wt = it.second;
        if (dist[u] != inf && ((dist[u] + wt) < dist[v])) {
          if (step == n - 1) {
            cout << "Negative cycle found\n ";
            return;
          }
          dist[v] = dist[u] + wt;
          parent[v] = u;
        }
      }
    }
  }
  for (ll i = 1; i <= n; i++)
    cout << dist[i] << " ";
  cout << endl;
}