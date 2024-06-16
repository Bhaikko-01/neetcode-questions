#include <bits/stdc++.h>

using namespace std;

string getKey(int i, int j)
{
  return to_string(i) + "," + to_string(j);
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid, int i, int j, unordered_map<string, int>& occured)
{
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  string key = getKey(i, j);

  if (i >= m || j >= n) {
    return 0;
  }

  if (obstacleGrid[i][j] == 1) {
    return 0;
  }

  if (i == m - 1 && j == n - 1) {
    return 1;
  }

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  int totalPaths = 0;

  totalPaths += uniquePathsWithObstacles(obstacleGrid, i, j + 1, occured);
  totalPaths += uniquePathsWithObstacles(obstacleGrid, i + 1, j, occured);

  occured[key] = totalPaths;

  return occured[key];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  unordered_map<string, int> occured;

  return uniquePathsWithObstacles(obstacleGrid, 0, 0, occured);
}

typedef long long ll;

int uniquePathsWithObstaclesDp(vector<vector<int>>& obstacleGrid)
{
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  vector<vector<ll>> dp(m, vector<ll>(n, 0));

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (obstacleGrid[i][j] == 1) {
        dp[i][j] = 0;
      } else if (i == m - 1 && j == n - 1) {
        dp[i][j] = 1;
      } else {
        ll totalPaths = 0;

        if (j + 1 < n) {
          totalPaths += dp[i][j + 1];
        }

        if (i + 1 < m) {
          totalPaths += dp[i + 1][j];
        }

        dp[i][j] = totalPaths;
      }
    }
  }

  return dp[0][0];
}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<vector<int>> obstacleGrid(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> obstacleGrid[i][j];
    }
  }

  cout << uniquePathsWithObstaclesDp(obstacleGrid) << endl;
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
