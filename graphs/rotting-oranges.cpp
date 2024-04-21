/**
 * 1. BFS - O(n) - [T + S]
 *      In BFS, at every iteration, we process neighbors of all nodes in one loop before going to next set of nodes
 *        At any moment, in queue, we will have combined neighbors of all nodes processed in last iteration
 *      If neighbors found by processing at current level,
 *        mins++
 *      Else if queue is empty, cannot traverse more
 *        stop iterating over nodes
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> coord;

void pushToPendingQueue(vector<vector<int>>& grid, queue<coord>& pendingCoord, int x, int y, int m, int n)
{
  if (x < 0 || y < 0 || x >= m || y >= n) {
    return;
  }

  if (grid[x][y] == 1) {
    grid[x][y] = 2;
    pendingCoord.push({ x, y });
  }
}

int orangesRotting(vector<vector<int>>& grid)
{
  int m = grid.size();
  int n = grid[0].size();

  queue<coord> pendingCoords;
  int mins = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 2) {
        pendingCoords.push({ i, j });
      }
    }
  }

  while (true) {
    int currElementsToProcess = pendingCoords.size();
    for (int i = 1; i <= currElementsToProcess; i++) {
      coord neighborCoord = pendingCoords.front();
      pendingCoords.pop();

      int x = neighborCoord.first,
          y = neighborCoord.second;

      pushToPendingQueue(grid, pendingCoords, x - 1, y, m, n);
      pushToPendingQueue(grid, pendingCoords, x + 1, y, m, n);
      pushToPendingQueue(grid, pendingCoords, x, y - 1, m, n);
      pushToPendingQueue(grid, pendingCoords, x, y + 1, m, n);
    }

    if (pendingCoords.empty()) {
      break;
    }

    mins++;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        return -1;
      }
    }
  }

  return mins;
}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<vector<int>> grid(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  cout << orangesRotting(grid) << endl;
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
