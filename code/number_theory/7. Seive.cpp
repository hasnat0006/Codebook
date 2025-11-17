const ll N = 1e7 + 5;
ll prime[N];
void sieveOfEratosthenes() {
  for (ll i = 2; i < N; i++)
    prime[i] = 1;
  for (ll i = 4; i < N; i += 2)
    prime[i] = 0;
  for (ll i = 3; i * i < N; i++) {
    if (prime[i]) {
      for (ll j = i * i; j < N; j += i * 2)
        prime[j] = 0;
    }
  }
}