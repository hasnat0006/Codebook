//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|11|2025 15:59:40            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

using u64 = uint64_t;
using u128 = __uint128_t;

ll MSLCM(ll n) {
	ll l = 1, r, val, ret = 0;
	while (l <= n) {
		val = n / l,r = n / val;
		ret += val * ((l+r)*(r-l+1)/2);
		l = r+1;
  }
	return ret-1;
}


void solve() {}

int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ll t = 1;
  // cin >> t;
  for (ll i = 1; i <= t; i++) {
    // cout << "Case " << i << ": ";
    solve();
  }
  return 0;
}