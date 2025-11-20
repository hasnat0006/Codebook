class GaussianElimination {
public:
  GaussianElimination(vector<vector<double>> matrix, vector<double> results)
      : matrix(matrix), results(results), n(matrix.size()) {}
  void solve() {
    fElim();
    bSub();
  }
  vector<vector<double>> matrix;
  vector<double> results, solution;
  ll n;
  void fElim() {
    for (ll i = 0; i < n; ++i) {
      ll maxRow = i;
      for (ll k = i + 1; k < n; ++k)
        if (abs(matrix[k][i]) > abs(matrix[maxRow][i]))
          maxRow = k;
      swap(matrix[i], matrix[maxRow]);
      swap(results[i], results[maxRow]);
      for (ll k = i + 1; k < n; ++k) {
        double factor = matrix[k][i] / matrix[i][i];
        for (ll j = i; j < n; ++j)
          matrix[k][j] -= factor * matrix[i][j];
        results[k] -= factor * results[i];
      }
    }
  }
  void bSub() {
    solution.resize(n);
    for (ll i = n - 1; i >= 0; --i) {
      solution[i] = results[i];
      for (ll j = i + 1; j < n; ++j)
        solution[i] -= matrix[i][j] * solution[j];
      solution[i] /= matrix[i][i];
    }
  }
};
