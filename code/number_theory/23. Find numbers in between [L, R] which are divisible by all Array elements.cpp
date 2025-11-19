void solve(ll* arr, ll N, ll L, ll R) { 
    ll LCM = arr[0];
    for (ll i = 1; i < N; i++) {
        LCM = (LCM * arr[i]) / 
            (__gcd(LCM, arr[i]));    
    }
    if ((LCM<L&& LCM * 2 > R) || LCM > R){        
   return;    
    }
    ll k = (L / LCM) * LCM;
    if (k < L) k = k + LCM;
    for (ll i = k; i <= R; i = i + LCM) 
        cout << i << ' ';
}
