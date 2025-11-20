class CRT {
  typedef long long vlong;
  typedef pair<vlong, vlong> pll;
  vector<pll> equations;

public:
  void clear() { equations.clear(); }
  vlong extended_euclid(vlong a, vlong b, vlong &x, vlong &y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    vlong x1, y1;
    vlong d = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
  }
  vlong inverse(vlong a, vlong m) {
    vlong x, y;
    vlong g = extended_euclid(a, m, x, y);
    if (g != 1)
      return -1;
    return (x % m + m) % m;
  }

  /** Add equation of the form x = r (mod m)*/
  void addEquation(vlong r, vlong m) { equations.push_back({r, m}); }
  pll solve() {
    if (equations.size() == 0)
      return {-1, -1};

    vlong a1 = equations[0].first;
    vlong m1 = equations[0].second;
    a1 %= m1;
    for (int i = 1; i < equations.size(); i++) {
      vlong a2 = equations[i].first;
      vlong m2 = equations[i].second;

      vlong g = __gcd(m1, m2);
      if (a1 % g != a2 % g)
        return {-1, -1};
      vlong p, q;
      extended_euclid(m1 / g, m2 / g, p, q);

      vlong mod = m1 / g * m2;
      vlong x = ((__int128)a1 * (m2 / g) % mod * q % mod +
                 (__int128)a2 * (m1 / g) % mod * p % mod) %
                mod;
      a1 = x;
      if (a1 < 0)
        a1 += mod;
      m1 = mod;
    }
    return {a1, m1};
  }
};
