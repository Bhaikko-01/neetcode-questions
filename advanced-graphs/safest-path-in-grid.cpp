#include <bits/stdc++.h>

using namespace std;

inline int getManhattanDistance(int a, int b, int x, int y) {
  return abs(a - x) + abs(b - y);
}

vector<vector<int>> getSafenessGrid(
  vector<vector<int>>& grid,
  vector<vector<int>>& thieves
)
{
  int n = grid.size();

  vector<vector<int>> safenessGrid(n, vector<int>(n, INT_MAX));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (vector<int>& thief: thieves) {
        int dis = getManhattanDistance(i, j, thief[0], thief[1]);

        safenessGrid[i][j] = min(dis, safenessGrid[i][j]);
      }
    }
  }

  return safenessGrid;
}

using pp = pair<int, int>;

struct MaxSafenessComparator {
  vector<vector<int>>& safenessGrid;

  MaxSafenessComparator(vector<vector<int>>& safenessGrid) : safenessGrid(safenessGrid) {}

  bool operator()(const pp& first, const pp& second) {
    return (
      safenessGrid[first.first][first.second] <
      safenessGrid[second.first][second.second]
    );
  }
};

vector<pp> getNeighbors(int n, int i, int j)
{
  vector<pp> neighbors;

  if (i - 1 >= 0) {
    neighbors.push_back({ i - 1, j });
  }

  if (j - 1 >= 0) {
    neighbors.push_back({ i, j - 1 });
  }

  if (i + 1 < n) {
    neighbors.push_back({ i + 1, j });
  }

  if (j + 1 < n) {
    neighbors.push_back({ i, j + 1 });
  }

  return neighbors;
}

int maximumSafenessFactor(vector<vector<int>>& grid)
{
  int n = grid.size();

  vector<vector<int>> thieves;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        thieves.push_back({ i, j });
      }
    }
  }

  vector<vector<int>> safenessGrid = getSafenessGrid(grid, thieves);
  int ans = INT_MAX;
  bool pathFound = false;
  vector<vector<int>> distances(n, vector<int>(n, INT_MIN));
  vector<vector<bool>> isVisited(n, vector<bool>(n, false));

  MaxSafenessComparator maxSafeness(safenessGrid);
  priority_queue<pp, vector<pp>, MaxSafenessComparator> pending(maxSafeness);

  pending.push({ 0, 0 });
  distances[0][0] = 0;

  while (!pending.empty()) {
    pp currNode = pending.top();
    int i = currNode.first,
        j = currNode.second;

    pending.pop();

    ans = min(ans, safenessGrid[i][j]);
    // cout << i << " " << j << " | " << safenessGrid[i][j] << endl;

    if (i == n - 1 && j == n - 1) {
      pathFound = true;
      break;
    }

    if (isVisited[i][j]) {
      continue;
    }

    isVisited[i][j] = true;

    vector<pp> neighbors = getNeighbors(n, i, j);
    for (const pp& neighbor: neighbors) {
      int neiI = neighbor.first;
      int neiJ = neighbor.second;

      if (isVisited[neiI][neiJ]) {
        continue;
      }

      int currDis = distances[i][j] + safenessGrid[neiI][neiJ];
      if (currDis > distances[neiI][neiJ]) {
        currDis = distances[neiI][neiJ];

        pending.push(neighbor);
      }
    }
  }

  if (pathFound) {
    return ans;
  }

  return 0;
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

  cout << maximumSafenessFactor(grid) << endl;
}

int main()
{
  solution();

  return 0;
}
