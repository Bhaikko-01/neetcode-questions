/**
 * 1. Brute Force - O((m*n)^2)
 *      Consider each cell as top left corner of square and
 *        try to expand it till biggest square possible
 *      Do this for cell with '1' and entirely skip search for '0'
 * 2. Subproblem Approach - O(m*n)
 *      A cell can be considered square if it is top right and all cell adjacent to it
 *        right, bottom and rightBottom makes a square
 *      If all of them makes square AND current cell is '1'
 *        then current cell will make square of length
 *          min(right, bottom, rightBottom) + 1
 *        otherwise it can make square if its `1` itself
 *      Border cells can only create square of length 1
 */

#include <bits/stdc++.h>

using namespace std;

string getKey(int x, int y)
{
  return to_string(x) + "," + to_string(y);
}

int maximalSquare(vector<vector<char>>& matrix, int x, int y, unordered_map<string, int>& dp)
{
  int m = matrix.size(),
      n = matrix[0].size();

  if (x >= m || y >= n) {
    return 0;
  }

  if (x == m - 1 || y == n - 1) {
    return matrix[x][y] == '1';
  }

  if (matrix[x][y] == '0') {
    return 0;
  }

  string key = getKey(x, y);

  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  int right = maximalSquare(matrix, x, y + 1, dp);
  int bottom = maximalSquare(matrix, x + 1, y, dp);
  int rightBottom = maximalSquare(matrix, x + 1, y + 1, dp);

  if (right == 0 || bottom == 0 || rightBottom == 0) {
    return matrix[x][y] == '1';
  }

  dp[key] = min(rightBottom, min(bottom, right)) + 1;
  return dp[key];
}

int maximalSquare(vector<vector<char>>& matrix)
{
  int maxAns = 0;

  int m = matrix.size(),
      n = matrix[0].size();

  unordered_map<string, int> dp;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == '1') {
        int len = maximalSquare(matrix, i, j, dp);

        maxAns = max(maxAns, len * len);
      }
    }
  }

  return maxAns;
}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<vector<char>> matrix(m, vector<char>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  cout << maximalSquare(matrix) << endl;
}

int main()
{
  solution();

  return 0;
}

/**
4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

5 5
1 1 1 1 0
1 1 1 1 0
1 1 1 1 1
1 1 1 1 1
0 0 1 1 1
 */
