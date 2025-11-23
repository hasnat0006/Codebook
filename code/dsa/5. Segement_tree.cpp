class SEGMENT_TREE {
public:
  vector<ll> v;
  vector<ll> seg;
  SEGMENT_TREE(ll n) {
    v.resize(n + 5);
    seg.resize(4 * n + 5);
  }
  //! initially: ti = 1, low = 1, high = n (number of elements in the array);
  void build(ll ti, ll low, ll high) {
    if (low == high) {
      seg[ti] = v[low];
      return;
    }
    ll mid = (low + high) / 2;
    build(2 * ti, low, mid);
    build(2 * ti + 1, mid + 1, high);
    seg[ti] = (seg[2 * ti] + seg[2 * ti + 1]);
  }
  //! initially: ti = 1, low = 1, high = n (number of elements in the array), (ql & qr)=user input in 1 based index;
  ll find(ll ti, ll tl, ll tr, ll ql, ll qr) {
    if (tl > qr || tr < ql) {
      return 0;
    }
    if (tl >= ql and tr <= qr)
      return seg[ti];
    ll mid = (tl + tr) / 2;
    ll l = find(2 * ti, tl, mid, ql, qr);
    ll r = find(2 * ti + 1, mid + 1, tr, ql, qr);
    return (l + r);
  }
  //! initially: ti = 1, tl = 1, tr = n (number of elements in the array), id = user input in 1 based indexing, val = updated value;
  void update(ll ti, ll tl, ll tr, ll id, ll val) {
    if (id > tr or id < tl)
      return;
    if (id == tr and id == tl) {
      seg[til] = val;
      return;
    }
    ll mid = (tl + tr) / 2;
    update(2 * ti, tl, mid, id, val);
    update(2 * ti + 1, mid + 1, tr, id, val);
    seg[ti] = (seg[2 * ti] + seg[2 * ti + 1]);
  }
};
// use 1 based indexing;
