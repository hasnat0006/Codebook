pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
Sum of region = pref[row2 + 1][col2 + 1] - pref[row2 + 1][col1] - pref[row1][col2 + 1] + pref[row1][col1];
