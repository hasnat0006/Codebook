ll cntOnes(ll n) {
  ll cnt = 0;
  for (ll i = 1; i <= n; i <<= 1) {
    ll x = (n + 1) / (i << 1);
    cnt += x * i;
    if ((n + 1) % i && n & i)
      cnt += (n + 1) % i;
  }
  return cnt;
}
