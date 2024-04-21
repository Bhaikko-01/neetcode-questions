/**
 * 1. Border DFS
 *      Run DFS for border values having 'O' and mark all the accessible values
 *        These values will never be convertible to 'X' as they are connected to border
 *        All the other 'O' will be convertible
 *      This works as we are finding regions which are not convertible and subtracting those from whole
 *        region will give us the answer
 *      only A ~= Whole - B
*/
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<char>>& board, int x, int y, int m, int n)
{
  if (x < 0 || y < 0 || x >= m || y >= n) {
    return;
  }

  if (board[x][y] == 'X' || board[x][y] == 'T') {
    return;
  }

  board[x][y] = 'T';

  dfs(board, x - 1, y, m, n);
  dfs(board, x + 1, y, m, n);
  dfs(board, x, y - 1, m, n);
  dfs(board, x, y + 1, m, n);
}

void solve(vector<vector<char>>& board)
{
  int m = board.size();
  int n = board[0].size();

  for (int i = 0; i < m; i++) {
    dfs(board, i, 0, m, n);
    dfs(board, i, n - 1, m, n);
  }

  for (int i = 0; i < n; i++) {
    dfs(board, 0, i, m, n);
    dfs(board, m - 1, i, m, n);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'T') {
        board[i][j] = 'O';
      } else if (board[i][j] == 'O') {
        board[i][j] = 'X';
      }
    }
  }
}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<vector<char>> board(m, vector<char>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  solve(board);

  cout << endl;

  for (auto x: board) {
    for (auto y: x) {
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
