class DisjollSet {
  vector<ll> par, sz, minElmt, maxElmt, cntElmt;

public:
  DisjollSet(ll n) {
    par.resize(n + 1);
    sz.resize(n + 1, 1);
    minElmt.resize(n + 1);
    maxElmt.resize(n + 1);
    cntElmt.resize(n + 1, 1);
    for (ll i = 1; i <= n; i++)
      par[i] = minElmt[i] = maxElmt[i] = i;
  }
  ll findUPar(ll u) {
    if (u == par[u])
      return u;
    return par[u] = findUPar(par[u]);
  }
  void unionBySize(ll u, ll v) {
    ll pU = findUPar(u);
    ll pV = findUPar(v);
    if (pU == pV)
      return;
    if (sz[pU] < sz[pV])
      swap(pU, pV);
    par[pV] = pU;
    sz[pU] += sz[pV];
    cntElmt[pU] += cntElmt[pV];
    minElmt[pU] = min(minElmt[pU], minElmt[pV]);
    maxElmt[pU] = max(maxElmt[pU], maxElmt[pV]);
  }
  ll getMinElementIntheSet(ll u) { return minElmt[findUPar(u)]; }
  ll getMaxElementIntheSet(ll u) { return maxElmt[findUPar(u)]; }
  ll getNumofElementIntheSet(ll u) { return cntElmt[findUPar(u)]; }
};
