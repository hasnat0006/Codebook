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

ll binaryExp(ll base, ll power, ll MOD = mod) {
  ll res = 1;
  while (power) {
    if (power & 1)
      res = (res * base) % MOD;
    base = ((base % MOD) * (base % MOD)) % MOD;
    power /= 2;
  }
  return res;
}

bool check_composite(ll n, ll a, ll d, ll s) {
  ll x = binaryExp(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (ll r = 1; r < s; r++) {
    x = (u128)x * x % n;
    if (x == n - 1)
      return false;
  }
  return true;
};
bool MillerRabin(ll n, ll iter = 5) {
  // returns true if n is probably prime, else returns false.
  if (n < 4)
    return n == 2 || n == 3;
  ll s = 0;
  ll d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    s++;
  }
  for (ll i = 0; i < iter; i++) {
    ll a = 2 + rand() % (n - 3);
    if (check_composite(n, a, d, s))
      return false;
  }
  return true;
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