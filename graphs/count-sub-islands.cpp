#include <bits/stdc++.h>

using namespace std;

bool countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j)
{
  int m = grid1.size(),
      n = grid1[0].size();

  if (i < 0 || j < 0 || i >= m || j >= n) {
    return true;
  }

  if (grid2[i][j] == 0 || grid2[i][j] == -1) {
    return true;
  }

  if (grid2[i][j] == 1 && grid1[i][j] == 0) {
    return false;
  }

  grid2[i][j] = -1;

  bool left = countSubIslands(grid1, grid2, i, j - 1);
  bool right = countSubIslands(grid1, grid2, i, j + 1);
  bool up = countSubIslands(grid1, grid2, i - 1, j);
  bool down = countSubIslands(grid1, grid2, i + 1, j);

  if (!left || !right || !up || !down) {
    return false;
  }

  return true;
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
{
  int m = grid1.size(),
      n = grid1[0].size();

  int count = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid2[i][j] == 1) {
        if (countSubIslands(grid1, grid2, i, j)) {
          count++;
        }
      }
    }
  }

  return count;
}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<vector<int>> grid1(m, vector<int>(n, 0));
  vector<vector<int>> grid2(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid1[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid2[i][j];
    }
  }

  cout << countSubIslands(grid1, grid2) << endl;
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

/**
1
5 5
1 1 1 0 0
0 1 1 1 1
0 0 0 0 0
1 0 0 0 0
1 1 0 1 1

1 1 1 0 0
0 0 1 1 1
0 1 0 0 0
1 0 1 1 0
0 1 0 1 0
*/
