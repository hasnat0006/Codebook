
vector<ll> createLPS(string pattern) {
  ll n = pattern.length(), idx = 0;
  vector<ll> lps(n);
  for (ll i = 1; i < n;) {
    if (pattern[idx] == pattern[i]) {
      lps[i] = idx + 1;
      idx++, i++;
    } else {
      if (idx != 0)
        idx = lps[idx - 1];
      else
        lps[i] = idx, i++;
    }
  }
  return lps;
}
ll kmp(string text, string pattern) {
  ll cnt_of_match = 0, i = 0, j = 0;
  vector<ll> lps = createLPS(pattern);
  while (i < text.length()) {
    if (text[i] == pattern[j])
      i++, j++; // i = text, j = pattern
    else {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
    if (j == pattern.length()) {
      cnt_of_match++;
      // the index where match found -> (i - pattern.length());
      j = lps[j - 1];
    }
  }
  return cnt_of_match;
}