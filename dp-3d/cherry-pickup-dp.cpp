/**
 * 1. Backtracking
 *     Combined path will look like as if two people tried to reach end
 *      If they go over same grid block then only one is able to pick it
 *    r1,c1 -> first person coords    r2, c2 -> second person coords => r1 + c1 = r2 + c2 meaning they both move same distance
 *    Four recursive calls based on r1,c1,r2,c2 AND r2 = r1+c1-c2
 *      P1, P2, r1,   c1,   r2,           c2
 *      D,  D,  r1+1, c1+0, r1+1+c1-c2=1, c2
 *      D,  R,  r1+1, c1+0, r1+c1-c2=0,   c2+1
 *      R,  D,  r1,   c1+1, r1+c1+1-c2=1, c2
 *      R,  R,  r1,   c1+1, r1+c1-c2=0,   c2+1
 */

#include <bits/stdc++.h>

using namespace std;

int cherryPickup(vector<vector<int>>& grid, int r1, int c1, int c2, vector<vector<vector<int>>>& dp)
{
  int n = grid.size();

  int r2 = r1 + c1 - c2;

  if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
    return INT_MIN;
  }

  if (dp[r1][c1][c2] != -1) {
    return dp[r1][c1][c2];
  }

  // P2 will also reach at same time
  if (r1 == n - 1 && c1 == n - 1) {
    return grid[r1][c1];
  }

  int cherries = grid[r1][c1] + grid[r2][c2];
  if (r1 == r2 && c1 == c2) {
    cherries = grid[r1][c1];
  }

  int downDown = cherryPickup(grid, r1 + 1, c1, c2, dp);
  int downRight = cherryPickup(grid, r1 + 1, c1, c2 + 1, dp);
  int rightDown = cherryPickup(grid, r1, c1 + 1, c2, dp);
  int rightRight = cherryPickup(grid, r1, c1 + 1, c2 + 1, dp);

  int currMaxCherries = max(max(max(downDown, downRight), rightDown), rightRight);

  if (currMaxCherries == INT_MIN) {
    dp[r1][c1][c2] = INT_MIN;
    return INT_MIN;
  }

  dp[r1][c1][c2] = currMaxCherries + cherries;

  return dp[r1][c1][c2];
}

int cherryPickup(vector<vector<int>>& grid)
{
  int n = grid.size();

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

  int ans = cherryPickup(grid, 0, 0, 0, dp);
  return max(0, ans);
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
