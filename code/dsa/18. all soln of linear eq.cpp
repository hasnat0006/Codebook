struct Combi {
  int n;
  vector<ll> facts, finvs, invs;
  Combi(int _n) : n(_n), facts(_n), finvs(_n), invs(_n) {
    facts[0] = finvs[0] = 1;
    invs[1] = 1;
    for (int i = 2; i < n; i++)
      invs[i] = invs[mod % i] * (-mod / i);
    for (int i = 1; i < n; i++) {
      facts[i] = facts[i - 1] * i;
      finvs[i] = finvs[i - 1] * invs[i];
    }
  }
  inline ll fact(int n) { return facts[n]; }
  inline ll finv(int n) { return finvs[n]; }
  inline ll inv(int n) { return invs[n]; }
  inline ll ncr(int n, int k) {
    return n < k ? 0 : facts[n] * finvs[k] * finvs[n - k];
  }
};
Combi C(N);

// returns the number of solutions to the equation
// x_1 + x_2 + ... + x_n = s and 0 <= l <= x_i <= r
ll yo(int n, int s, int l, int r) {
  if (s < l * n)
    return 0;
  s -= l * n;
  r -= l;
  ll ans = 0;
  for (int k = 0; k <= n; k++) {
    ll cur = C.ncr(s - k - k * r + n - 1 + 1, n - 1 + 1) * C.ncr(n, k);
    if (k & 1)
      ans -= cur;
    else
      ans += cur;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << yo(3, 3, 0, 1) << '\n';
  return 0;
}
