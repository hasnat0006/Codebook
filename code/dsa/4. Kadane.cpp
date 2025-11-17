// return maximum subarray sum.
ll kadense(ll arr[], ll n) {
  ll mxsm = arr[0], curr_s = arr[0];
  for (ll i = 1; i < n; i++) {
    curr_s = max(arr[i], curr_s + arr[i]);
    mxsm = max(mxsm, curr_s);
  }
  return mxsm;
}
