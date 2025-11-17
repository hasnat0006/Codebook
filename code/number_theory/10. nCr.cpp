// 1:
// more space, less time
const ll MAX = 1e7 + 5;
vector<ll> fact(MAX), ifact(MAX), inv(MAX);
void factorial() {
  inv[1] = fact[0] = ifact[0] = 1;
  for (ll i = 2; i < MAX; i++)
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  for (ll i = 1; i < MAX; i++)
    fact[i] = (fact[i - 1] * i) % mod;
  for (ll i = 1; i < MAX; i++)
    ifact[i] = ifact[i - 1] * inv[i] % mod;
}
ll nCr(ll n, ll r) {
  if (r < 0 || r > n)
    return 0;
  return (ll)fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}
// 2:
// less space, more time
const ll MAX = 1e7 + 10;
vector<ll> fact(MAX), inv(MAX);
void factorial() {
  fact[0] = 1;
  for (ll i = 1; i < MAX; i++)
    fact[i] = (i * fact[i - 1]) % mod;
}
ll binaryExp(ll a, ll n, ll M = mod){}; // needs to implement
void inverse() {
  for (ll i = 0; i < MAX; ++i)
    inv[i] = binaryExp(fact[i], mod - 2);
}
ll nCr(ll a, ll b) {
  if (a < b or a < 0 or b < 0)
    return 0;
  ll de = (inv[b] * inv[a - b]) % mod;
  return (fact[a] * de) % mod;
}
// 3:
// nCr mod m where m is not prime
ll C_mod_p(ll n, ll k, ll p) {
  if (k > n)
    return 0;
  vector<ll> fac(p);
  fac[0] = 1;
  for (int i = 1; i < p; i++)
    fac[i] = fac[i - 1] * i % p;

  ll res = 1;
  while (n || k) {
    ll ni = n % p, ki = k % p;
    if (ki > ni)
      return 0;
    res = res * fac[ni] % p * modInv(fac[ki], p) % p * modInv(fac[ni - ki], p) %
          p;
    n /= p;
    k /= p;
  }
  return res;
}
// compute nCr mod composite m (non-prime)
ll nCr_mod_m(ll n, ll k, ll m) {
  // Step 1: factorize m
  vector<int> primes;
  int tmp = m;
  for (int i = 2; i * i <= tmp; i++) {
    if (tmp % i == 0) {
      primes.push_back(i);
      while (tmp % i == 0)
        tmp /= i;
    }
  }
  if (tmp > 1)
    primes.push_back(tmp);

  // Step 2: compute result mod each prime
  vector<ll> rem, mod;
  for (int p : primes) {
    rem.push_back(C_mod_p(n, k, p));
    mod.push_back(p);
  }
  // Step 3: Chinese Remainder Theorem (combine)
  ll res = 0;
  for (int i = 0; i < (int)mod.size(); i++) {
    ll Mi = m / mod[i];
    ll invMi = binaryExp(Mi, mod[i] - 2, mod[i]); // modular inverse
    res = (res + rem[i] * Mi % m * invMi % m) % m;
  }

  return res;
}