// Addition :
ll mod_add(ll a, ll b, ll MOD = mod) {
  a = a % MOD, b = b % MOD;
  return (((a + b) % MOD) + MOD) % MOD;
}
// Subtraction :
ll mod_sub(ll a, ll b, ll MOD = mod) {
  a = a % MOD, b = b % MOD;
  return (((a - b) % MOD) + MOD) % MOD;
}
// Multiplication :
ll mod_mul(ll a, ll b, ll MOD = mod) {
  a = a % MOD, b = b % MOD;
  return (((a * b) % MOD) + MOD) % MOD;
}
// Division :
ll mminvprime(ll a, ll b) { return binaryExp(a, b - 2, b); }
ll mod_div(ll a, ll b, ll MOD = mod) {
  a = a % MOD, b = b % MOD;
  return (mod_mul(a, mminvprime(b, MOD), MOD) + MOD) % MOD;
}
