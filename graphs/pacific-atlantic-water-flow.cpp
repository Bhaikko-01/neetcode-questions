/**
 * 1. Brute force - O((n * m)^2)
 *      DFS for every cell to find path to left/top border and right/bottom border
 *      If found, add to possible answer
 * 2. Partial DFS and Combine results (Border DFS) - O(m * n)
 *      Find all cells reachable for atlantic border, running DFS on top and left border
 *      Find all cells reachable for pacific border, running DFS on right and bottom border
 *        compare height with prevHeight to ensure cell is reachable
 *      Store reachable cells in separate matrices
 *      Final answer would be intersection of two traversed matrcies of atlantic and pacific
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Coord;

void dfs(vector<vector<int>>& heights, int x, int y, int m, int n, int prevHeight, vector<vector<bool>>& pacificReach)
{
  if (x < 0 || y < 0 || x >= m || y >= n) {
    return;
  }

  if (pacificReach[x][y] || heights[x][y] < prevHeight) {
    return;
  }

  pacificReach[x][y] = true;

  dfs(heights, x - 1, y, m, n, heights[x][y], pacificReach);
  dfs(heights, x, y - 1, m, n, heights[x][y], pacificReach);
  dfs(heights, x + 1, y, m, n, heights[x][y], pacificReach);
  dfs(heights, x, y + 1, m, n, heights[x][y], pacificReach);
}

// ! 2
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
  int m = heights.size();
  int n = heights[0].size();

  vector<vector<bool>> pacificReach(m, vector<bool>(n, false));
  vector<vector<bool>> atlanticReach(m, vector<bool>(n, false));

  // Processing Pacific
  for (int i = 0; i < n; i++) {
    dfs(heights, 0, i, m, n, heights[0][i], pacificReach);
  }

  for (int i = 0; i < m; i++) {
    dfs(heights, i, 0, m, n, heights[i][0], pacificReach);
  }

  // Processing Atlantic
  for (int i = 0; i < n; i++) {
    dfs(heights, m - 1, i, m, n, heights[m - 1][i], atlanticReach);
  }

  for (int i = 0; i < m; i++) {
    dfs(heights, i, n - 1, m, n, heights[i][n - 1], atlanticReach);
  }

  vector<vector<int>> ans;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (pacificReach[i][j] && atlanticReach[i][j]) {
        ans.push_back({ i, j });
      }
    }
  }

  return ans;
}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<vector<int>> heights(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> heights[i][j];
    }
  }

  vector<vector<int>> ans = pacificAtlantic(heights);

  for (auto x: ans) {
    for (auto y: x) {
      cout << y << " ";
    }

    cout << endl;
  }
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
