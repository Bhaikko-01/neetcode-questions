#include <bits/stdc++.h>

using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)
{
  int n = matrix.size();

  if (i >= n) {
    return 0;
  }

  if (j < 0 || j >= n) {
    return INT_MAX;
  }

  if (dp[i][j] != INT_MAX) {
    return dp[i][j];
  }

  int currCount = matrix[i][j];

  int leftDown  = minFallingPathSum(matrix, i + 1, j - 1, dp);
  int down      = minFallingPathSum(matrix, i + 1, j, dp);
  int rightDown = minFallingPathSum(matrix, i + 1, j + 1, dp);

  int minAll = min(min(leftDown, rightDown), down);

  if (minAll == INT_MAX) {
    dp[i][j] = currCount;
  } else {
    dp[i][j] = currCount + minAll;
  }

  return dp[i][j];
}

int minFallingPathSum(vector<vector<int>>& matrix)
{
  int minCount = INT_MAX;
  int n = matrix.size();

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

  for (int i = 0; i < n; i++) {
    int currCount = minFallingPathSum(matrix, 0, i, dp);

    minCount = min(minCount, currCount);
  }

  return minCount;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  cout << minFallingPathSum(matrix) << endl;
}

int main()
{
  solution();

  return 0;
}
