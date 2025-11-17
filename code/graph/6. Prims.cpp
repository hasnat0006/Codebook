// TC: O(ElogV)
typedef pair<ll, ll> pll;
class Prims {
  map<ll, vector<pll>> graph;
  map<ll, ll> visited;

public:
  void addEdge(ll u, ll v, ll w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  vector<ll> path(pll start) {
    vector<ll> ans;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    // cost vs node
    pq.push({start.second, start.first});
    while (!pq.empty()) {
      pair<ll, ll> curr = pq.top();
      pq.pop();
      if (visited[curr.second])
        continue;
      visited[curr.second] = 1;
      ans.push_back(curr.second);
      for (auto i : graph[curr.second]) {
        if (visited[i.first])
          continue;
        pq.push({i.second, i.first});
      }
    }
    return ans;
  }
};
