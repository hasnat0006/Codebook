// sum over subsets
for (int i = 0; i < B; i++) {
  for (int mask = 0; mask < (1 << B); mask++) {
    if ((mask & (1 << i)) != 0) {
      f[mask] += f[mask ^ (1 << i)];
    }
  }
}

// sum over supersets
for (int i = 0; i < B; i++) {
  for (int mask = (1 << B) - 1; mask >= 0; mask--) {
    if ((mask & (1 << i)) == 0)
      g[mask] += g[mask ^ (1 << i)];
  }
}
// submask
for (int mask = 1; mask < (1 << 5); mask++) {
  for (int submask = mask; submask > 0; submask = ((submask - 1) & mask)) {
    int subset = mask ^ submask;
  }
}
/**
* we have to use SOS dp te idea is that we can iterate over all mask and using there subset get the actual value
* the first is we have to find for each value in the array how many y we have so that x|y = x
* if a binary is 1010 all possible y is 1000 0010 0000
* so basically the subset of x
* using sos dp we can find some properties from somethings subset
* the idea is that we will consider first what if we can't change any bit to manipulate x what would be the ans
* the 1 bit , 2 bit...log2(x)bit change from the right(LSB)
* we will check what are the changes between binary
* for example in the property of x|y = x
* dp[i][x] = from right i bit can change and for x value
* so initially this is the frequency of the x
* then dp[1][x] will be dp[0][x] if 1 bit is 0, because we obviousily can't change it otherwise it will not be same after OR'ed
* but if 1th bit is 1
* dp[1][x] = dp[0][x] + dp[0][different with the mask or (x-(1<<i-1))] -> here is the right side part we basically needs to find in order to complete the code thats it
* for example another case is x&y = x;
* now lets see when is this property hold
* if x is 1010
* for 0 we can use other value
* for 1 we can use only 1
* now lets see 1010 -> for 1 bit change the subset(superset) is 1011
* for 2 bit change 1011 1010
* for 3 bit change 1110 1011 1111 1010
* so if you see what are the diff berween bit 2 change and bit 3 change it is just the 1110 and 1111 now this is 1011+0100 -> 1111 and 1010 + 0100 -> 1110 so each element in 2 bit change + (1<<(bit-1)); <--- this is the observation part
* and now final one is x&y !=0
*  if 1010 ->
* for 1 bit change 1010 1011
* for 2 bit change 1010 1000 1001 1011
* for 3 bit change 1010 1000 1001 1011 1100 ..
* for 4 bit change 1010 1000 0010 ...
* for 1010 just before mx bit all subset of 101 will be discared, if use any subset of 0101 like 0100 it will not change anything cause 1010 & 0100 is 1000 the change is not on 0 bits
* now how the code goes?
* we iterate over all x
* the we iterate from 0 bit change to max bit change  and store in dp
* TC of sos dp is (b*2^b);
**/