/**
 * 1. Check indiviual element validation
 *  Use hashmap to check occurence of each character
 *  Iterate through row of that element
 *  Iterate through col of that element
 *  Check block of that element
 * 2. Check Rows, Cols and block indiviually
*/

#include <bits/stdc++.h>

using namespace std;

#define N 9

typedef unordered_map<char, bool> charBoolMapping;
char dotChar = '.';

// ! 2.
bool validateRow(vector<vector<char>>& board, int row)
{
  charBoolMapping occurence;

  for (int i = 0; i < N; i++) {
    char el = board[row][i];
    if (el == dotChar) {
      continue;
    }

    if (occurence[el]) {
      return false;
    }

    occurence[el] = true;
  }

  return true;
}

// ! 2.
bool validateColumn(vector<vector<char>>& board, int col)
{
  charBoolMapping occurence;

  for (int i = 0; i < N; i++) {
    char el = board[i][col];
    if (el == dotChar) {
      continue;
    }

    if (occurence[el]) {
      return false;
    }

    occurence[el] = true;
  }

  return true;
}

// ! 2.
bool validateBlocks(vector<vector<char>>& board)
{
  const int gridSize = N / 3;

  for (int rowGrid = 0; rowGrid < gridSize; rowGrid++) {
    for (int colGrid = 0; colGrid < gridSize; colGrid++) {
      charBoolMapping occurence;

      for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
          char el = board[i + gridSize * rowGrid][j + gridSize * colGrid];

          if (el == dotChar) {
            continue;
          }

          if (occurence[el]) {
            return false;
          }

          occurence[el] = true;
        }
      }
    }
  }


  return true;
}

// ! 2.
bool isValidSudoku(vector<vector<char>>& board) {
  bool allBlocksCorrect = validateBlocks(board);

  if (!allBlocksCorrect) {
    return false;
  }

  bool allRowsCorrect = true;
  bool allColumnsCorrect = true;

  for (int i = 0; i < N; i++) {
    allRowsCorrect = allRowsCorrect && validateRow(board, i);
    allColumnsCorrect = allColumnsCorrect && validateColumn(board, i);

    if (!allRowsCorrect || !allColumnsCorrect) {
      return false;
    }
  }

  return true;
}

void solution()
{
  vector<vector<char>> board(N);
  for (int i = 0; i < 9; i++) {
    board[i] = vector<char>(N);

    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j];
    }

    cout << endl;
  }

  cout << isValidSudoku(board) << endl;
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
 * input 1 - 5 3 . . 7 . . . . 6 . . 1 9 5 . . . . 9 8 . . . . 6 . 8 . . . 6 . . . 3 4 . . 8 . 3 . . 1 7 . . . 2 . . . 6 . 6 . . . . 2 8 . . . . 4 1 9 . . 5 . . . . 8 . . 7 9
 * input 2 - 8 3 . . 7 . . . . 6 . . 1 9 5 . . . . 9 8 . . . . 6 . 8 . . . 6 . . . 3 4 . . 8 . 3 . . 1 7 . . . 2 . . . 6 . 6 . . . . 2 8 . . . . 4 1 9 . . 5 . . . . 8 . . 7 9
*/
