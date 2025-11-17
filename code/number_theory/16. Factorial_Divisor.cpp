ll factorialDivisors(ll n) {
  ll result = 1;
  for (ll i = 0; i < allPrimes.size(); i++) {
    ll p = allPrimes[i];
    ll exp = 0;
    while (p <= n) {
      exp = exp + (n / p);
      p = p * allPrimes[i];
    }
    result = result * (exp + 1);
  }
  return result;
}