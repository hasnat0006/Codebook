bool prime(ll n) {
  if (n < 2)
    return false;
  if (n <= 3)
    return true;
  if (!(n % 2) || !(n % 3))
    return false;
  for (ll i = 5; i * i <= n; i += 6) {
    if (!(n % i) || !(n % (i + 2)))
      return false;
  }
  return true;
}
// TC: sqrt(n) / 6;