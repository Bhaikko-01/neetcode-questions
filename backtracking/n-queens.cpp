/**
 * 1. Backtracking
 *      Try placing current queen based on current board
 *        If possible, move to next column
 *        Else backtrack and mark placed queen position as '.'
 *      Make sure to provide initial queen position before using recursion
 *
 * Time complexity
 *  At each iteration, O(n) work is done to find placeable queen
 *  At each level, there are n^x iterations where x is depth
 *  Hence, Total computation = n*n + n*n^2 + n*n^3 + ---- n*n^n = n^n ~ O(n!)
 * Space complexity
 *  Each iteration takes O(1) space and depth of tree is O(n)
 *    hence O(n) space
*/

#include <bits/stdc++.h>

using namespace std;

bool canPlace(int r, int c, int n, vector<string>& currBoard)
{
  for (int i = 0; i < c; i++) {
    if (currBoard[r][i] == 'Q') {
      return false;
    }
  }

  int i = r - 1, j = c - 1;
  while (true) {
    if (i < 0 || j < 0) {
      break;
    }

    if (currBoard[i][j] == 'Q') {
      return false;
    }

    i--;
    j--;
  }

  i = r + 1;
  j = c - 1;
  while (true) {
    if (i >= n || j < 0) {
      break;
    }

    if (currBoard[i][j] == 'Q') {
      return false;
    }

    i++;
    j--;
  }

  return true;
}

void solveNQueens(int c, int n, vector<string> currBoard, vector<vector<string>>& ans)
{
  if (c == n) {
    ans.push_back(currBoard);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (canPlace(i, c, n, currBoard)) {
      currBoard[i][c] = 'Q';
      solveNQueens(c + 1, n, currBoard, ans);
      currBoard[i][c] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n)
{
  vector<vector<string>> ans;

  for (int i = 0; i < n; i++) {
    vector<string> currBoard(n, string(n, '.'));

    currBoard[i][0] = 'Q';
    solveNQueens(1, n, currBoard, ans);
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<string>> ans = solveNQueens(n);

  for (auto x: ans) {
    for (string y: x) {
      cout << y << " ";
    }
    cout << endl;
  }
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
