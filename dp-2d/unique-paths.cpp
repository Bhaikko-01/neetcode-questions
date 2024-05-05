/**
 * 1. Backtracking
 *      Call recursion on i+1 and j+1 to get path
 *        if i==m-1 and j==n-1 then return 1 as only one way possible
 *      Add checks for out of bounds
 * 2. DP - Bottom UP
 *      For boundaries, possible path will be 1
 *      Call DP from m-2 and n-2
*/

#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int i, int j, int m, int n, vector<vector<int>>& occured)
{
  if (i == m - 1 || j == n - 1) {
    return 1;
  }

  if (i >= m || j >= n) {
    return 0;
  }

  if (occured[i][j] != -1) {
    return occured[i][j];
  }

  int totalPaths = 0;

  totalPaths += uniquePaths(i + 1, j, m, n, occured);
  totalPaths += uniquePaths(i, j + 1, m, n, occured);

  occured[i][j] = totalPaths;

  return occured[i][j];
}

int uniquePaths(int m, int n)
{
  vector<vector<int>> occured(m, vector<int>(n, -1));

  return uniquePaths(0, 0, m, n, occured);
}

int uniquePathsDp(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    dp[m - 1][i] = 1;
  }

  for (int i = 0; i < m; i++) {
    dp[i][n - 1] = 1;
  }

  for (int i = m - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      int totalPaths = 0;

      if (i + 1 < m) {
        totalPaths += dp[i + 1][j];
      }

      if (j + 1 < n) {
        totalPaths += dp[i][j + 1];
      }

      dp[i][j] = totalPaths;
    }
  }

  return dp[0][0];
}

void solution()
{
  int m, n;
  cin >> m >> n;

  cout << uniquePathsDp(m, n) << endl;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    solution();
  }

  return 0;
}
