ll a[100] = {0}, b[100] = {0}, f[100] = {0};
ll n = 0, m = 0;
ll main(void) {
  cin >> n;
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  cin >> m;
  for (ll i = 1; i <= m; i++)
    cin >> b[i];
  for (ll i = 1; i <= n; i++) {
    ll k = 0;
    for (ll j = 1; j <= m; j++) {
      if (a[i] > b[j] && f[j] > k)
        k = f[j];
      else if (a[i] == b[j] && k + 1 > f[j])
        f[j] = k + 1;
    }
  }
  ll and = 0;
  for (ll i = 1; i <= m; i++)
    if (f[i] > ans)
      ans = f[i];
  cout << and << endl;
  return 0;
}
