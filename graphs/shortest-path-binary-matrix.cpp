/**
 * 1. BFS with 8 directions - O(n^2)
 */

#include <bits/stdc++.h>

using namespace std;

bool isOutOfBound(vector<vector<int>>& grid, int i, int j)
{
  int n = grid.size();

  return (
    i < 0 || i >= n ||
    j < 0 || j >= n
  );
}

vector<vector<int>> getNeighbors(vector<vector<int>>& grid, int row, int col)
{
  vector<vector<int>> neighbors;

  for (int x = -1; x <= 1; x++) {
    for (int y = -1; y <= 1; y++) {
      if (x == 0 && y == 0) {
        continue;
      }

      if (
        !isOutOfBound(grid, row + x, col + y) &&
        grid[row + x][col + y] != -1 &&
        grid[row + x][col + y] != 1
      ) {
        neighbors.push_back({ row + x, col + y });
      }
    }
  }

  return neighbors;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
  queue<vector<int>> pending;

  int n = grid.size();

  if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
    return -1;
  }

  int pathCount = 1;

  pending.push({ 0, 0 });
  grid[0][0] = -1;

  while (!pending.empty()) {
    int currCount = pending.size();

    for (int i = 1; i <= currCount; i++) {
      vector<int> currCoord = pending.front();
      pending.pop();

      if (currCoord[0] == n - 1 && currCoord[1] == n - 1) {
        return pathCount;
      }

      vector<vector<int>> neighbors = getNeighbors(grid, currCoord[0], currCoord[1]);

      for (vector<int> neighbor: neighbors) {
        grid[neighbor[0]][neighbor[1]] = -1;

        pending.push(neighbor);
      }
    }

    pathCount++;
  }

  return -1;
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

  cout << shortestPathBinaryMatrix(grid) << endl;
}

int main()
{
  solution();

  return 0;
}
