ll disarrange(ll n) {
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;
  return (n - 1) * (disarrange(n - 1) + disarrange(n - 2));
}
// D(n) = (n!)/e
