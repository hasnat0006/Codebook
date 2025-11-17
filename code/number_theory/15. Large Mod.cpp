ll mod(string &num, ll a) {
  ll res = 0;
  for (ll i = 0; i < num.length(); i++)
    res = (res * 10 + num[i] - '0') % a;
  return res;
}
