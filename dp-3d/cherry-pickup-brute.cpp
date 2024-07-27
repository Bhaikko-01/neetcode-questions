/**
 * 1. Backtracking
 *      Reach bottom right once and start reverse path from there
 *      Get ans this way
 */

#include <bits/stdc++.h>

using namespace std;

int cherryPickupBackwards(vector<vector<int>>& grid, int x, int y)
{
  int n = grid.size();

  if (x < 0 || y < 0 || grid[x][y] == -1) {
    return INT_MIN;
  }

  if (x == 0 && y == 0) {
    return grid[x][y];
  }

  int currCount = grid[x][y];
  grid[x][y] = 0;

  int leftCount = cherryPickupBackwards(grid, x, y - 1);
  int upCount = cherryPickupBackwards(grid, x - 1, y);

  int maxCount = max(leftCount, upCount);

  grid[x][y] = currCount;

  return maxCount + currCount;
}

int cherryPickup(vector<vector<int>>& grid, int x, int y)
{
  int n = grid.size();

  if (x >= n || y >= n || grid[x][y] == -1) {
    return INT_MIN;
  }

  if (x == n - 1 && y == n - 1) {
    return cherryPickupBackwards(grid, x, y);
  }

  int currCount = grid[x][y];
  grid[x][y] = 0;

  int rightCount = cherryPickup(grid, x, y + 1);
  int bottomCount = cherryPickup(grid, x + 1, y);

  int maxCount = max(rightCount, bottomCount);

  grid[x][y] = currCount;

  return maxCount + currCount;
}

int cherryPickup(vector<vector<int>>& grid)
{
  return max(0, cherryPickup(grid, 0, 0));
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  cout << cherryPickup(grid) << endl;
}

int main()
{
  solution();

  return 0;
}
