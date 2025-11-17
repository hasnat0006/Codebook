// TC : O(ElogE)
typedef pair<ll, ll> edge;
class Graph {
  vector<pair<ll, edge>> G, T;
  vector<ll> parent;
  ll cost = 0;

public:
  Graph(ll n) {
    for (ll i = 0; i < n; i++)
      parent.push_back(i);
  }
  void add_edges(ll u, ll v, ll wt) { G.push_back({wt, {u, v}}); }
  ll find_set(ll n) {
    if (n == parent[n])
      return n;
    else
      return find_set(parent[n]);
  }

  void union_set(ll u, ll v) { parent[u] = parent[v]; }

  void kruskal() {
    sort(G.begin(), G.end());
    for (auto it : G) {
      ll uRep = find_set(it.second.first);
      ll vRep = find_set(it.second.second);
      if (uRep != vRep) {
        cost += it.first;
        T.push_back(it);
        union_set(uRep, vRep);
      }
    }
  }
  ll get_cost() { return cost; }
  void print() {
    for (auto it : T)
      cout << it.second.first << " " << it.second.second << ": " << it.first << endl;
  }
};

// g.add_edges(u, v, wt);
// g.kruskal();
