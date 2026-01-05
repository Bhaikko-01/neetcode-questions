/**
 * 1. Brute Force - O(log(m * n))
 *    Convert into 1D array and binary search on that
 * 2. Convert indexes from 1D to 2D - O(log(m * n)) and binary search
 *      l = 0, r = m * n - 1, n is number of columns
 *      mid = (l + r) / 2
 *      Find rowIdx and colIdx for 2D matrix
 *        rowIdx = mid / n
 *        colIdx = mid % n
 *      if (matrix[rowIdx][colIdx] == target) => found
 *      else assign l and r accordingly based on comparison
*/

#include <bits/stdc++.h>

using namespace std;

// ! 2.
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
  int m = matrix.size(),
      n = matrix[0].size();

  int l = 0, r = m * n - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    int rowIndex = mid / n;
    int colIndex = mid % n;

    int el = matrix[rowIndex][colIndex];

    if (el == target) {
      return true;
    } else if (target > el) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return false;
}

void solution()
{
  int m, n, target;
  cin >> m >> n >> target;

  vector<vector<int>> matrix(m);
  for (int i = 0; i < m; i++) {
    matrix[i] = vector<int>(n);

    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  cout << searchMatrix(matrix, target) << endl;
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
