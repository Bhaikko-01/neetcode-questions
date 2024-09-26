#include <bits/stdc++.h>

using namespace std;

string getKey(int x, int y)
{
  return to_string(x) + "," + to_string(y);
}

int minPathSum(vector<vector<int>>& grid, int x, int y, unordered_map<string, int>& dp)
{
  int n = grid.size();
  int m = grid[0].size();

  if (x == n - 1 && y == m - 1) {
    return grid[x][y];
  }

  if (x == n || y == m) {
    return INT_MAX;
  }

  string key = getKey(x, y);

  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  int down = minPathSum(grid, x + 1, y, dp);
  int right = minPathSum(grid, x, y + 1, dp);

  int minPath = min(down, right);

  if (minPath == INT_MAX) {
    dp[key] = minPath;
    return dp[key];
  }

  dp[key] = minPath + grid[x][y];

  return dp[key];
}

int minPathSum(vector<vector<int>>& grid)
{
  unordered_map<string, int> dp;

  return minPathSum(grid, 0, 0, dp);
}

void solution()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  cout << minPathSum(grid) << endl;
}

int main()
{
  solution();

  return 0;
}
