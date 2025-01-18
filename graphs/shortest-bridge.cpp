/**
 * 1. DFS + BFS - O(n^2)
 *      Use DFS to get first island
 *      Instead of starting BFS from one point, start as whole island
 *        by pushing all points of first island to queue
 *      Shortest bridge is first time we reached using initial all points using BFS
 *        This will work as only neighbor points are affected so node farther than already reached
 *          node cannot affect it as it will have been already visited
 */

#include <bits/stdc++.h>

using namespace std;

bool isPointOutOfBounds(vector<vector<int>>& grid, int x, int y)
{
  int n = grid.size();

  return (
    x < 0 || x >= n ||
    y < 0 || y >= n
  );
}

void getIslands(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& island)
{
  int n = grid.size();

  if (
    isPointOutOfBounds(grid, x, y) ||
    grid[x][y] == -1 || grid[x][y] == 0
  ) {
    return;
  }

  grid[x][y] = -1;

  island.push_back({ x, y });

  getIslands(grid, x - 1, y, island);
  getIslands(grid, x + 1, y, island);
  getIslands(grid, x, y - 1, island);
  getIslands(grid, x, y + 1, island);
}

vector<vector<int>> getNeighbors(vector<vector<int>>& grid, int x, int y)
{
  vector<vector<int>> neighbors;

  if (!isPointOutOfBounds(grid, x + 1, y)) {
    neighbors.push_back({ x + 1, y });
  }

  if (!isPointOutOfBounds(grid, x - 1, y)) {
    neighbors.push_back({ x - 1, y });
  }

  if (!isPointOutOfBounds(grid, x, y + 1)) {
    neighbors.push_back({ x, y + 1 });
  }

  if (!isPointOutOfBounds(grid, x, y - 1)) {
    neighbors.push_back({ x, y - 1 });
  }

  return neighbors;
}

int shortestBridge(vector<vector<int>>& grid, vector<vector<int>>& island1)
{
  queue<vector<int>> pendingCoords;

  for (vector<int> point: island1) {
    int x = point[0];
    int y = point[1];

    pendingCoords.push(point);
  }

  int count = 0;

  while (!pendingCoords.empty()) {
    int currCoords = pendingCoords.size();

    for (int i = 1; i <= currCoords; i++) {
      vector<int> coord = pendingCoords.front();
      pendingCoords.pop();

      int x = coord[0],
          y = coord[1];

      vector<vector<int>> neighbors = getNeighbors(grid, x, y);

      for (vector<int> neighbor: neighbors) {
        int x1 = neighbor[0];
        int y1 = neighbor[1];

        if (grid[x1][y1] == 1) {
          return count;
        }

        if (grid[x1][y1] == 0) {
          grid[x1][y1] = -1;

          pendingCoords.push(neighbor);
        }
      }
    }

    count++;
  }

  return count;
}

vector<vector<int>> getFirstIsland(vector<vector<int>>& grid)
{
  int n = grid.size();

  vector<vector<int>> island;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        getIslands(grid, i, j, island);
        return island;
      }
    }
  }

  return island;
}

int shortestBridge(vector<vector<int>>& grid)
{
  int n = grid.size();

  vector<vector<int>> island1 = getFirstIsland(grid);

  return shortestBridge(grid, island1);
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

  cout << shortestBridge(grid) << endl;
}

/**
 *
5
1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1

5
0 1 0 0 0
0 1 0 1 1
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
 */

int main()
{
  solution();

  return 0;
}
