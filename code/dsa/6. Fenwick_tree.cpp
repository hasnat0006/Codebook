struct FenwickTree {
  vector<ll> bit; // binary indexed tree
  ll n;
  FenwickTree(ll n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }
  ll sum(ll r) {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }
  ll sum(ll l, ll r) { return sum(r) - sum(l - 1); }
  void add(ll idx, ll delta) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};

// minimum
struct FenwickTreeMin {
  vector<ll> bit;
  ll n;
  const ll INF = (ll)1e9;
  FenwickTreeMin(ll n) {
    this->n = n;
    bit.assign(n, INF);
  }
  FenwickTreeMin(vector<ll> a) : FenwickTreeMin(a.size()) {
    for (size_t i = 0; i < a.size(); i++)
      update(i, a[i]);
  }
  ll getmin(ll r) {
    ll ret = INF;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret = min(ret, bit[r]);
    return ret;
  }
  void update(ll idx, ll val) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] = min(bit[idx], val);
  }
};
