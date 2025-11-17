// TC : O(V + E)
map<ll, vector<ll>> adj;
map<ll, ll> degree;
set<ll> nodes;
vector<ll> ans;
// adj: graph input, degree: cnt indegree,
// node: unique nodes, ans: path
ll c = 0;
void topo_sort() {
  queue<ll> qu;
  // traverse all the nodes and check if its degree is 0 or not..
  for (ll i : nodes) {
    if (degree[i] == 0)
      qu.push(i);
  }
  while (!qu.empty()) {
    ll top = qu.front();
    qu.pop();
    ans.push_back(top);
    for (ll i : adj[top]) {
      degree[i]--;
      if (degree[i] == 0) {
        qu.push(i);
      }
    }
  }
}