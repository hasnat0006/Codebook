vector<ll> nth_prime;
const ll MX = 86200005;
bitset<MX> visited;
void optimized_prime() {
  nth_prime.push_back(2);
  for (ll i = 3; i < MX; i += 2) {
    if (visited[i])
      continue;
    nth_prime.push_back(i);
    if (1ll * i * i > MX)
      continue;
    for (ll j = i * i; j < MX; j += i + i)
      visited[j] = true;
  }
}