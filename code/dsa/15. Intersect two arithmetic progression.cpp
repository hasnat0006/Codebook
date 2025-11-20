using T = __int128;
// ax + by = __gcd(a, b)
// returns __gcd(a, b)
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = y = 0;
  T yy = x = 1;
  while (b) {
    T q = a / b;
    T t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
pair<T, T> CRT(T a1, T m1, T a2, T m2) {
  T p, q;
  T g = extended_euclid(m1, m2, p, q);
  if (a1 % g != a2 % g)
    return make_pair(0, -1);
  T m = m1 / g * m2;
  p = (p % m + m) % m;
  q = (q % m + m) % m;
  return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) % m,
                   m);
}
// intersecting AP of two APs: (a1 + d1x) and (a2 + d2x)
pair<ll, ll> intersect(ll a1, ll d1, ll a2, ll d2) {
  auto x = CRT(a1 % d1, d1, a2 % d2, d2);
  ll a = x.first, d = x.second;
  if (d == -1)
    return {0, 0}; // empty
  ll st = max(a1, a2);
  a = a < st ? a + ((st - a + d - 1) / d) : a; // while (a < st) a += d;
  return {a, d};
}
