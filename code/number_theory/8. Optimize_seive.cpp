
vector<ll> sieve(const ll N, const ll Q = 17, const ll L = 1 << 15) {
  static const ll rs[] = {1, 7, 11, 13, 17, 19, 23, 29};
  struct P {
    P(ll p) : p(p) {}
    ll p;
    ll pos[8];
  };
  auto approx_prime_count = [](const ll N) -> ll {
    return N > 60184 ? N / (log(N) - 1.1) : max(1., N / (log(N) - 1.11)) + 1;
  };
  const ll v = sqrt(N), vv = sqrt(v);
  vector<bool> isp(v + 1, true);
  for (ll i = 2; i <= vv; ++i)
    if (isp[i]) {
      for (ll j = i * i; j <= v; j += i)
        isp[j] = false;
    }
  const ll rsize = approx_prime_count(N + 30);
  vector<ll> primes = {2, 3, 5};
  ll psize = 3;
  primes.resize(rsize);

  vector<P> sprimes;
  size_t pbeg = 0;
  ll prod = 1;
  for (ll p = 7; p <= v; ++p) {
    if (!isp[p])
      continue;
    if (p <= Q)
      prod *= p, ++pbeg, primes[psize++] = p;
    auto pp = P(p);
    for (ll t = 0; t < 8; ++t) {
      ll j = (p <= Q) ? p : p * p;
      while (j % 30 != rs[t])
        j += p << 1;
      pp.pos[t] = j / 30;
    }
    sprimes.push_back(pp);
  }

  vector<unsigned char> pre(prod, 0xFF);
  for (size_t pi = 0; pi < pbeg; ++pi) {
    auto pp = sprimes[pi];
    const ll p = pp.p;
    for (ll t = 0; t < 8; ++t) {
      const unsigned char m = ~(1 << t);
      for (ll i = pp.pos[t]; i < prod; i += p)
        pre[i] &= m;
    }
  }
  const ll block_size = (L + prod - 1) / prod * prod;
  vector<unsigned char> block(block_size);
  unsigned char *pblock = block.data();
  const ll M = (N + 29) / 30;

  for (ll beg = 0; beg < M; beg += block_size, pblock -= block_size) {
    ll end = min(M, beg + block_size);
    for (ll i = beg; i < end; i += prod) {
      copy(pre.begin(), pre.end(), pblock + i);
    }
    if (beg == 0)
      pblock[0] &= 0xFE;
    for (size_t pi = pbeg; pi < sprimes.size(); ++pi) {
      auto &pp = sprimes[pi];
      const ll p = pp.p;
      for (ll t = 0; t < 8; ++t) {
        ll i = pp.pos[t];
        const unsigned char m = ~(1 << t);
        for (; i < end; i += p)
          pblock[i] &= m;
        pp.pos[t] = i;
      }
    }
    for (ll i = beg; i < end; ++i) {
      for (ll m = pblock[i]; m > 0; m &= m - 1) {
        primes[psize++] = i * 30 + rs[__builtin_ctz(m)];
      }
    }
  }
  assert(psize <= rsize);
  while (psize > 0 && primes[psize - 1] > N)
    --psize;
  primes.resize(psize);
  return primes;
}
// it takes 500ms for generating prime upto 1e9