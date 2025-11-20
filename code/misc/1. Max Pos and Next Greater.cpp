const ll MXX = 1e5 + 5;
ll mxtree[4 * MXX], arr[MXX];
void maxtree(ll idx, ll left, ll right) {
  if (left == right)
    mxtree[idx] = left;
  else {
    ll mid = (left + right) / 2;
    maxtree(idx * 2, left, mid);
    maxtree(idx * 2 + 1, mid + 1, right);
    ll left = mxtree[idx * 2];
    ll right = mxtree[idx * 2 + 1];
    if (arr[left] < arr[right])
      mxtree[idx] = right;
    else
      mxtree[idx] = left;
  }
}
ll mxPos(ll idx, ll tleft, ll tright, ll qleft, ll qright) {
  if (qleft > qright)
    return -1;
  if (qleft == tleft and qright == tright)
    return mxtree[idx];
  ll tmid = (tleft + tright) / 2;
  ll left = mxPos(idx * 2, tleft, tmid, qleft, min(qright, tmid));
  ll right = mxPos(idx * 2 + 1, tmid + 1, tright, max(qleft, tmid + 1), qright);
  ll ans;
  if (left == -1)
    ans = right;
  else if (right == -1)
    ans = left;
  else if (arr[left] < arr[right])
    ans = right;
  else
    ans = left;
  return ans;
}
ll main() {
  ll t = 1, n, q, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
      cin >> arr[i];
    stack<ll> stk;
    ll nge[n];
    stk.push(0);
    for (ll i = 1; i < n; i++) {
      while (stk.size() and arr[stk.top()] < arr[i]) {
        nge[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    while (stk.size()) {
      nge[stk.top()] = n;
      stk.pop();
    }
    ll ans[n];
    ans[n - 1] = 0;
    for (ll i = n - 2; i >= 0; i--) {
      ll tmp = nge[i];
      if (tmp == n)
        ans[i] = 0;
      else
        ans[i] = ans[tmp] + 1;
    }
    maxtree(1, 0, n - 1);
    for (ll i = 0; i < q; i++) {
      cin >> a >> b;
      if (a > b)
        swap(a, b);
      cout << ans[mxPos(1, 0, n - 1, a - 1, b - 1)] << "\n";
    }
  }
}
