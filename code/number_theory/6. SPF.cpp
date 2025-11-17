// smallest prime factor using seive
const ll N = 1e7 + 5;
ll spf[N];
void smallestPrimeFactorUsingSeive() {
  for (ll i = 2; i < N; i++) {
    if (spf[i] == 0) {
      for (ll j = i; j < N; j += i) {
        if (spf[j] == 0)
          spf[j] = i;
      }
    }
  }
}

// smallest factor of a number
ll factor(ll n) {
  ll a;
  if (n % 2 == 0)
    return 2;
  for (a = 3; a * a <= n; a += 2) {
    if (n % a == 0)
      return a;
  }
  return n;
}
// complete factorization
ll r;
while (n > 1) {
  r = factor(n);
  cout << r << '\n';
  n /= r;
}
