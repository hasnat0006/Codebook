struct Manacher {
  vector<ll> p[2];
  string s;
  // p[1][i] = (max odd length palindrome centered at i) / 2 [floor division]
  // p[0][i] = same for even, it considers the right center
  // e.g. for s = "abbabba", p[1][3] = 3, p[0][2] = 2
  Manacher(string s) {
    this->s = s;
    ll n = s.size();
    p[0].resize(n + 1);
    p[1].resize(n);
    for (ll z = 0; z < 2; z++) {
      for (ll i = 0, l = 0, r = 0; i < n; i++) {
        ll t = r - i + !z;
        if (i < r)
          p[z][i] = min(t, p[z][l + t]);
        ll L = i - p[z][i], R = i + p[z][i] - !z;
        while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
          p[z][i]++, L--, R++;
        if (R > r)
          l = L, r = R;
      }
    }
  }
  bool is_palindrome(ll l, ll r) {
    ll mid = (l + r + 1) / 2, len = r - l + 1;
    return 2 * p[len % 2][mid] + len % 2 >= len;
  }
  string get_palin(ll i, bool odd = true) {
    ll len = p[odd][i];
    return s.substr(i - len, 2 * len + 1 - !odd);
  }
};
