// n! mod p : Here P is mod value
// For binaryExp we call 1.6 function
ll factmod(ll n, ll p) {
  ll res = 1;
  while (n > 1) {
    res = (res * binaryExp(p - 1, n / p, p)) % p;
    for (ll i = 2; i <= n % p; ++i)
      res = (res * i) % p;
    n /= p;
  }
  return (res % p);
}