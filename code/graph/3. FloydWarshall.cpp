// TC : O(n ^ 3)
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;
typedef vector<ll> VI;
typedef vector<VI> VVI;

bool FloydWarshall(VVT &w, VVI &prev) {
  ll n = w.size();
  prev = VVI(n, VI(n, -1));

  for (ll k = 0; k < n; k++) {
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        if (w[i][j] > w[i][k] + w[k][j]) {
          w[i][j] = w[i][k] + w[k][j];
          prev[i][j] = k;
        }
      }
    }
  }

  // check for negative weight cycles
  for (ll i = 0; i < n; i++)
    if (w[i][i] < 0)
      return false;
  return true;
}