// ! CHECK OPTIMISATION

#include <bits/stdc++.h>
#include <new>

using namespace std;

using pp = pair<int, int>;

inline int distance(int x0, int y0, int x1, int y1) {
  return abs(x0 - x1) + abs(y0 - y1);
}

inline bool isValidCoord(int n, int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < n;
}

string getKey(const pp& p) {
  return to_string(p.first) + "," + to_string(p.second);
}

pp maxDistance(
  vector<vector<int>>& grid,
  int startX, int startY,
  vector<vector<bool>>& visited,
  unordered_map<string, pp>& nearestLandCoord
) {
  int n = grid.size();

  queue<pp> pending;
  pp startCoord = { startX, startY };
  pending.push(startCoord);

  string startKey = getKey(startCoord);

  if (nearestLandCoord.find(startKey) != nearestLandCoord.end()) {
    return nearestLandCoord[startKey];
  }

  visited[startX][startY] = true;

  while (!pending.empty()) {
    int currElementsToProcess = pending.size();

    for (int i = 0; i < currElementsToProcess; i++) {
      pp curr = pending.front();
      pending.pop();

      int x = curr.first,
          y = curr.second;
      pp neighborCoord = { x, y };

      if (grid[x][y] == 1) {
        pp finalCoord = { x, y };

        nearestLandCoord[startKey] = finalCoord;

        return finalCoord;
      }

      string neighborKey = getKey(neighborCoord);

      if (nearestLandCoord.find(neighborKey) != nearestLandCoord.end()) {
        return nearestLandCoord[neighborKey];
      }

      if (isValidCoord(n, x + 1, y) && !visited[x + 1][y]) {
        visited[x + 1][y] = true;
        pending.push({ x + 1, y });
      }

      if (isValidCoord(n, x - 1, y) && !visited[x - 1][y]) {
        visited[x - 1][y] = true;
        pending.push({ x - 1, y });
      }

      if (isValidCoord(n, x, y + 1) && !visited[x][y + 1]) {
        visited[x][y + 1] = true;
        pending.push({ x, y + 1});
      }

      if (isValidCoord(n, x, y - 1) && !visited[x][y - 1]) {
        visited[x][y - 1] = true;
        pending.push({ x, y - 1 });
      }
    }
  }

  return { -1, -1 };
}

int maxDistance(vector<vector<int>>& grid)
{
  int n = grid.size();
  int ans = -1;

  unordered_map<string, pp> nearestLandCoord;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 0) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pp landCoords = maxDistance(grid, i, j, visited, nearestLandCoord);
        int landCoordsX = landCoords.first;
        int landCoordsY = landCoords.second;

        if (landCoordsX != -1) {
          int currDistance = distance(i, j, landCoordsX, landCoordsY);
          ans = max(ans, currDistance);
        }
      }
    }
  }

  return ans;
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

  cout << maxDistance(grid) << endl;
}

int main()
{
  solution();

  return 0;
}
