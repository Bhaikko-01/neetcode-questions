/**
 * 1. Graph iteration - O(1)
 *      From current position, simply search within constraints
 *        Adjacent cell will always be opposite color
 *        Set rowStart and colStart after leaving one cell and
 *          start search from there for same color
 *        Helper function accepts rMoveParam and cMoveParam for avoiding code repeatition
 */

#include <bits/stdc++.h>

using namespace std;

#define N 8

bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color, int rMoveParam, int cMoveParam)
{
  char oppositeColor = color == 'B' ? 'W' : 'B';

  if (
    rMove + rMoveParam >= 0 && rMove + rMoveParam < N &&
    cMove + cMoveParam >= 0 && cMove + cMoveParam < N &&
    board[rMove + rMoveParam][cMove + cMoveParam] != oppositeColor
  ) {
    return false;
  }

  int rStart = rMove + 2 * rMoveParam;
  int cStart = cMove + 2 * cMoveParam;

  while (
    rStart >= 0 && rStart < N &&
    cStart >= 0 && cStart < N
  ) {
    if (board[rStart][cStart] == '.') {
      return false;
    }

    if (board[rStart][cStart] == color) {
      return true;
    }

    rStart += rMoveParam;
    cStart += cMoveParam;
  }

  return false;
}

bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color)
{
  return (
    checkMove(board, rMove, cMove, color, +1, +0) ||
    checkMove(board, rMove, cMove, color, -1, +0) ||
    checkMove(board, rMove, cMove, color, +0, +1) ||
    checkMove(board, rMove, cMove, color, +0, -1) ||
    checkMove(board, rMove, cMove, color, -1, +1) ||
    checkMove(board, rMove, cMove, color, -1, -1) ||
    checkMove(board, rMove, cMove, color, +1, -1) ||
    checkMove(board, rMove, cMove, color, +1, +1)
  );
}

/**
 *
4 3 B
. . . B . . . .
. . . W . . . .
. . . W . . . .
. . . W . . . .
W B B . W W W B
. . . B . . . .
. . . B . . . .
. . . W . . . .

4 4 W
. . . B . . . .
. B . . W . . .
. . W . . . . .
. . . W B . . .
. . . . . . . .
. . . . B W . .
. . . . . . W .
. . . . . . . B

7 4 B
W W . B . B B .
W B . . W B . .
B B B B W W B .
W B . . B B B .
W W B . W . B B
B . B W . B . .
. B B W B B . .
B B W . * B . .
 */

void solution()
{
  int rMove, cMove;
  char color;
  cin >> rMove >> cMove >> color;

  vector<vector<char>> board(8, vector<char>(8));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  cout << checkMove(board, rMove, cMove, color) << endl;
}

int main()
{
  solution();

  return 0;
}
