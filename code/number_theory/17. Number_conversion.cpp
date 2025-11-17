// 10 - ary to m - ary
char a[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
string tenToM(ll n, ll m) {
  ll temp = n;
  string result = "";
  while (temp != 0) {
    result = a[temp % m] + result;
    temp /= m;
  }
  return result;
}

// m - ary to 10 - ary
string num = "0123456789ABCDE";
ll mToTen(string n, ll m) {
  ll multi = 1;
  ll result = 0;
  for (ll i = n.size() - 1; i >= 0; i--) {
    result += num.find(n[i]) * multi;
    multi *= m;
  }
  return result;
}
