
struct BigInteger {
  string str;
  // Constructor to initialize
  // BigInteger with a string
  BigInteger(string s) { str = s; }
  // Overload + operator to add
  // two BigInteger objects
  BigInteger operator+(const BigInteger &b) {
    string a = str, c = b.str;
    ll alen = a.length(), clen = c.length();
    ll n = max(alen, clen);
    if (alen > clen)
      c.insert(0, alen - clen, '0');
    else if (alen < clen)
      a.insert(0, clen - alen, '0');
    string res(n + 1, '0');
    ll carry = 0;
    for (ll i = n - 1; i >= 0; i--) {
            ll digit=(a[i -'0')+(c[i]-'0')
    +carry;
            carry = digit / 10;
            res[i + 1] = digit % 10 + '0';
    }
    if (carry == 1) {
            res[0] = '1';
            return BigInteger(res);
    } else
            return BigInteger(res.substr(1));
  }

  // Overload - operator to subtract
  // first check which number is greater and then subtract
  BigInteger operator-(const BigInteger &b) {
    string a = str;
    string c = b.str;
    ll alen = a.length(), clen = c.length();
    ll n = max(alen, clen);
    if (alen > clen)
            c.insert(0, alen - clen, '0');
    else if (alen < clen)
            a.insert(0, clen - alen, '0');
    if (a < c) {
            swap(a, c);
            swap(alen, clen);
    }
    string res(n, '0');
    ll carry = 0;
    for (ll i = n - 1; i >= 0; i--) {
            ll digit = (a[i] - '0') - (c[i] - '0') - carry;
            if (digit < 0)
              digit += 10, carry = 1;
            else
              carry = 0;
            res[i] = digit + '0';
    }
    // remove leading zeros
    ll i = 0;
    while (i < n && res[i] == '0')
            i++;
    if (i == n)
            return BigInteger("0");
    return BigInteger(res.substr(i));
  }

  // Overload * operator to multiply
  // two BigInteger objects
  BigInteger operator*(const BigInteger &b) {
    string a = str, c = b.str;
    ll alen = a.length(), clen = c.length();
    ll n = alen + clen;
    string res(n, '0');
    for (ll i = alen - 1; i >= 0; i--) {
            ll carry = 0;
            for (ll j = clen - 1; j >= 0; j--) {
              ll digit =
                  (a[i] - '0') * (c[j - '0']) + (res[i + j + 1] - '0') + carry;
              carry = digit / 10;
              res[i + j + 1] = digit % 10 + '0';
            }
            res[i] += carry;
    }
    ll i = 0;
    while (i < n && res[i] == '0')
            i++;
    if (i == n)
            return BigInteger("0");
    return BigInteger(res.substr(i));
  }

  // Overload << operator to output
  // BigInteger object
  friend ostream &operator<<(ostream &out, const BigInteger &b) {
    out << b.str;
    return out;
  }
};