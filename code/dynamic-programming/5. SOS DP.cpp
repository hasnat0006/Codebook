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
SOS DP (Sum Over Subsets Dynamic Programming) - 5 Key Points:
 1. CORE IDEA: Build DP table dp[i][mask] = answer considering first i bits of mask Transition: dp[i][mask] = dp[i-1][mask] + dp[i-1][mask ^ (1<<(i-1))]
 2. SUBSET SUM: For x|y = x, iterate bits and add contributions from subsets If bit i is set in mask, add dp[i-1][mask without bit i]
 3. SUPERSET SUM: For x&y = x, iterate in reverse to handle supersets  If bit i is unset in mask, add dp[i-1][mask with bit i set]
 **/