void findNumberOfSimpleCycles(int N, vector<vector<int>> adj) {
  int ans = 0;
  int dp[(1 << N)][N];
  memset(dp, 0, sizeof dp);
  for (int mask = 0; mask < (1 << N); mask++) {
    int nodeSet = __builtin_popcountll(mask);
    int firstSetBit = __builtin_ffsl(mask);
    if (nodeSet == 1)
      dp[mask][firstSetBit] = 1;
    else {
      for (int j = firstSetBit + 1; j < N; j++) {
        if ((mask & (1 << j))) {
          int newNodeSet = mask ^ (1 << j);
          for (int k = 0; k < N; k++) {
            if ((newNodeSet & (1 << k)) && adj[k][j]) {
              dp[mask][j] += dp[newNodeSet][k];
              if (adj[j][firstSetBit] && nodeSet > 2)
                ans += dp[mask][j];
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}
