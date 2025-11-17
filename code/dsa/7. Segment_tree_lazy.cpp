class SEGMENT_TREE {
public:
  vector<ll> v;
  vector<ll> seg;
  vector<ll> lazy;
  SEGMENT_TREE(ll n) {
    v.resize(n + 5, 0);
    seg.resize(4 * n + 5, 0);
    lazy.resize(4 * n + 5, 0);
  }
  void pull(ll ti) { seg[ti] = (seg[2 * ti] & seg[2 * ti + 1]); }
  void push(ll ti, ll tl, ll tr) {
    if (lazy[ti] == 0)
      return;
    seg[ti] |= lazy[ti];
    if (tl != tr) {
      lazy[2 * ti] |= lazy[ti];
      lazy[2 * ti + 1] |= lazy[ti];
    }
    lazy[ti] = 0;
  }
  //! llially: ti = 1, low = 1, high = n(number of elements in the array);
  void build(ll ti, ll low, ll high) {
    lazy[ti] = 0;
    if (low == high) {
      seg[ti] = v[low];
      return;
    }
    ll mid = (low + high) / 2;
    build(2 * ti, low, mid);
    build(2 * ti + 1, mid + 1, high);
    pull(ti);
  }
  //! llially: ti = 1, low = 1, high = n(number of elements in the array), (ql
  //! & qr) = user input in 1 based indexing;
  ll query(ll ti, ll tl, ll tr, ll ql, ll qr) {
    push(ti, tl, tr);
    if (tl > qr || tr < ql) {
      return (1LL << 32) - 1;
    }
    if (tl >= ql and tr <= qr)
      return seg[ti];
    ll mid = (tl + tr) / 2;
    ll l = query(2 * ti, tl, mid, ql, qr);
    ll r = query(2 * ti + 1, mid + 1, tr, ql, qr);
    return (l & r);
  }
  //! llially: ti = 1, tl = 1, tr = n(number of elements in the array), id =
  //! user input in 1 based indexing, val = updated value;
  void update(ll ti, ll tl, ll tr, ll idL, ll idR, ll val) {
    push(ti, tl, tr);
    if (idR < tl or tr < idL)
      return;
    if (idL <= tl and tr <= idR) {
      lazy[ti] |= val;
      push(ti, tl, tr);
      return;
    }
    ll mid = (tl + tr) / 2;
    update(2 * ti, tl, mid, idL, idR, val);
    update(2 * ti + 1, mid + 1, tr, idL, idR, val);
    pull(ti);
  }
  // use 1 based indexing for input and queries and update;
};
