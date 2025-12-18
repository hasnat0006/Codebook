ll calculateGrundy(ll n, vector<ll> &grundy, const vector<ll> &moves) {
  if (grundy[n] != -1)
    return grundy[n];
  unordered_set<ll> s;
  for (ll move : moves) {
    if (n >= move) {
      s.insert(calculateGrundy(n - move, grundy, moves));
    }
  }
  ll g = 0;
  while (s.count(g))
    g++;
  return grundy[n] = g;
}
vector<ll> computeGrundy(ll maxN, const vector<ll> &moves) {
  vector<ll> grundy(maxN + 1, -1);
  grundy[0] = 0;
  for (ll i = 1; i <= maxN; ++i) {
    calculateGrundy(i, grundy, moves);
  }
  return grundy;
}
/*
1. Nim = all xor
2. Misere Nim = Nim + corner case: if all piles are 1,reverse(nim)
3. Bogus Nim = Nim
4. Staircase Nim = Odd indexed pile Nim (Even indexed pile doesnt matter, as one player can give bogus moves to drop all even piles to ground)
5. Sprague Grundy = Every impartial game under the normal play convention is equivalent to a one-heap game of nim
*/
