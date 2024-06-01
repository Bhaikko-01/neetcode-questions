#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

pp getIndexesForNumber(int currNumber, int n)
{
  int i = (currNumber - 1) / n;
  int j = (currNumber - 1) % n;

  if (i & 1) {
    j = n - 1 - j;
  }
  i = n - 1 - i;

  return { i, j };
}

int snakesAndLadders(vector<vector<int>>& board, int currNumber)
{
  int n = board.size();
  int dest = n * n;

  int count = 0;

  queue<int> pending;
  pending.push(1);

  board[n - 1][0] = 0;

  while (!pending.empty()) {
    int currLevelSize = pending.size();

    for (int i = 0; i < currLevelSize; i++) {
      int el = pending.front();
      pending.pop();

      for (int j = 1; j <= 6; j++) {
        int newPos = el + j;

        if (newPos == dest) {
          return count + 1;
        }

        if (newPos > dest) {
          continue;
        }

        pp posCoords = getIndexesForNumber(newPos, n);
        int x = posCoords.first, y = posCoords.second;

        if (board[x][y] == 0) {
          continue;
        }

        int val = board[x][y] == -1 ? newPos : board[x][y];
        board[x][y] = 0;

        if (val == dest) {
          return count + 1;
        }

        pending.push(val);
      }
    }

    count++;
  }

  return count;
}

int snakesAndLadders(vector<vector<int>>& board)
{
  int ans = snakesAndLadders(board, 1);

  return ans == INT_MAX ? -1 : ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  cout << snakesAndLadders(board) << endl;
}

/**
1
6
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 35 -1 -1 13 -1
-1 -1 -1 -1 -1 -1
-1 15 -1 -1 -1 -1
*/

int main()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    solution();
  }

  return 0;
}
