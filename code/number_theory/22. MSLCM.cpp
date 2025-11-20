//For a given number N, maximum sum LCM indicates the set of numbers whose LCM is N and summation is maximum. Let, MSLCM(N) denote this maximum sum of numbers. Given the value of N you will have to find the value: ∑(i=2->n) MSLCM(i)
ll MSLCM(ll n) {
	ll l = 1, r, val, ret = 0;
	while (l <= n) {
		val = n / l,r = n / val;
		ret += val * ((l+r)*(r-l+1)/2);
		l = r+1;
}
	return ret-1;
}
