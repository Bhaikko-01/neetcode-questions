/**
 * 1. DFS Problem - (k*4^n) [T], O(k) [S], k is word length
 *      Add checks for index out of bounds, currCharacter not matched and already visited
 *      Traverse all 4 possiblities for word search
 *      If word not found, revert isTraversed tracker for a grid after recursion is finised
*/

#include <bits/stdc++.h>

using namespace std;

bool exist(vector<vector<char>>& board, int i, int j, int currWordIndex, string word, int m, int n)
{
  if (currWordIndex == word.size()) {
    return true;
  }

  if (i < 0 || j < 0 || i >= m || j >= n) {
    return false;
  }

  if (board[i][j] == '-' || word[currWordIndex] != board[i][j]) {
    return false;
  }

  char currLetter = board[i][j];
  // Used to mark if the current position is visited
  board[i][j] = '-';

  bool wordFound = exist(board, i + 1, j, currWordIndex + 1, word, m, n) ||
                   exist(board, i - 1, j, currWordIndex + 1, word, m, n) ||
                   exist(board, i, j + 1, currWordIndex + 1, word, m, n) ||
                   exist(board, i, j - 1, currWordIndex + 1, word, m, n);

  if (wordFound) {
    return true;
  }

  // Reverting isVisited marker
  board[i][j] = currLetter;
  return false;
}

bool exist(vector<vector<char>>& board, string word)
{
  int m = board.size();
  int n = board[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (exist(board, i, j, 0, word, m, n)) {
        return true;
      }
    }
  }

  return false;
}

void solution()
{
  int m, n;
  cin >> m >> n;

  string word;
  cin >> word;

  vector<vector<char>> board(m, vector<char>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  cout << exist(board, word) << endl;
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
