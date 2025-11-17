void catalan(ll n) {
  ll res = 1;
  cout << res << " ";
  for (ll i = 1; i < n; i++) {
    res = (res * (4 * i - 2)) / (i + 1);
    cout << res << " ";
  }
}
