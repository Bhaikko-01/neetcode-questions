/**
 * 1. DFS - O(m*n)
 *      Use Depth first search to traverse connected 1's
 *      Mark traversed point as '2'
 *      Make sure in DFS to check for out of bounds index first then value
 *        otherwise SEG Fault will occur
 *      Area of current node will be area of all 4 directions plus 1
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y, int m, int n)
{
  if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || grid[x][y] == -1) {
    return 0;
  }

  grid[x][y] = -1;

  int area = 1;

  area += dfs(grid, x + 1, y, m, n);
  area += dfs(grid, x - 1, y, m, n);
  area += dfs(grid, x, y + 1, m, n);
  area += dfs(grid, x, y - 1, m, n);

  return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
  int maxArea = 0;

  int m = grid.size();
  int n = grid[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        int currArea = dfs(grid, i, j, m, n);
        maxArea = max(maxArea, currArea);
      }
    }
  }

  return maxArea;
}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  cout << maxAreaOfIsland(grid) << endl;
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
