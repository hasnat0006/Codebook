using vvi = vector<vector<ll>>;
 
vvi martixMul(vvi &a, vvi &b) {
  ll r = a.size(), c = b[0].size();
  vvi ans(r, vector<ll>(c, 0));
  for (ll i = 0; i < r; i++) {
    for (ll j = 0; j < c; j++) {
      ans[i][j] = 0;
      for (ll k = 0; k < r; k++) {
        ans[i][j] += (a[i][k] * b[k][j]) % mod;
        ans[i][j] %= mod;
      }
    }
  }
  return ans;
}
 
vvi martixExp(vvi base, ll power, ll MOD = mod) {
  vvi ans = base; // change the ans accordingly
  while (power) {
    if (power & 1)
      ans = martixMul(ans, base);
    base = martixMul(base, base);
    power /= 2;
  }
  return ans;
}
