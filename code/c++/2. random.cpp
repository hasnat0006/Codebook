#define accuracy chrono::steady_clock::now().time_since_epoch().count()
mt19937 rng(accuracy);

ll rand(ll l, ll r) {
  uniform_int_distribution<ll> ludo(l, r);
  return ludo(rng);
}
