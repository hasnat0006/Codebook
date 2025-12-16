typedef long long LL;
LL arr[60][60], res[60][60], tmp[60][60], m;
void matMul(LL a[][60], LL b[][60], LL mod) {
  for (ll i = 0; i < m; i++)
    for (ll j = 0; j < m; j++) {
      tmp[i][j] = 0;
      for (ll k = 0; k < m; k++) {
        tmp[i][j] += (a[i][k] * b[k][j]) % mod;
        tmp[i][j] %= mod;
      }
    }
}

void power(LL n, LL mod) {
  for (ll i = 0; i < m; i++)
    for (ll j = 0; j < m; j++)
      if (i == j)
        res[i][j] = 1;
      else
        res[i][j] = 0;
  while (n) {
    if (n & 1) {
      matMul(res, arr, mod);
      for (ll i = 0; i < m; i++)
        for (ll j = 0; j < m; j++)
          res[i][j] = tmp[i][j];
      n--;
    } else {
      matMul(arr, arr, mod);
      for (ll i = 0; i < m; i++)
        for (ll j = 0; j < m; j++)
          arr[i][j] = tmp[i][j];
      n /= 2;
    }
  }
}