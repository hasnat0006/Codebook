bool isLeap(ll n) {
  if (n % 100 == 0)
    return (n % 400 == 0);
  else
    return (n % 4 == 0);
}
// leap year between l and r
ll calNum(ll y) { return (y / 4) - (y / 100) + (y / 400); }
ll leapNum(ll l, ll r) { return calNum(r) - calNum(--l); }
