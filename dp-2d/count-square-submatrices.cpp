/**
 * 1. 2D Array - O(n^3)
 *      - Pick an index and move diagonally and check if it makes a valid square
 *      - If it does, add 1
 *      - No need to check whole square, newly added side can be checked to see if
 *          bigger square is valid or not
 */

#include <bits/stdc++.h>

using namespace std;

int countSquaresBrute(vector<vector<int>>& matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();

  int maxSizeSquare = min(n, m);

  int numSquares = 0;

  for (int currSize = 1; currSize <= maxSizeSquare; currSize++) {
    for (int startX = 0; startX < n; startX++) {
      for (int startY = 0; startY < m; startY++) {
        int endX = startX + currSize - 1;
        int endY = startY + currSize - 1;

        // cout << currSize << " | " << startX << " " << startY << " " << endX << " " << endY << endl;

        if (endX < n && endY < m) {
          bool isCurrSquare = true;
          for (int i = startX; i <= endX; i++) {
            for (int j = startY; j <= endY; j++) {
              cout << i << " " << j << endl;
              if (matrix[i][j] == 0) {
                isCurrSquare = false;
                break;
              }
            }

            if (!isCurrSquare) {
              break;
            }
          }

          if (isCurrSquare) {
            numSquares++;
          }
        }

        // cout << "------------" << endl;
      }
    }
  }

  return numSquares;
}

int countSquares(vector<vector<int>>& matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();

  int numSquares = 0;

  for (int startX = 0; startX < n; startX++) {
    for (int startY = 0; startY < m; startY++) {
      if (matrix[startX][startY] == 1) {
        bool zeroFound = false;

        int currStartX = startX;
        int currStartY = startY;

        while (currStartX < n && currStartY < m) {
          for (int i = startX; i <= currStartX; i++) {
            if (matrix[i][currStartY] == 0) {
              zeroFound = true;
            }
          }

          for (int i = startY; i <= currStartY; i++) {
            if (matrix[currStartX][i] == 0) {
              zeroFound = true;
            }
          }

          if (zeroFound) {
            currStartX--;
            currStartY--;
            break;
          } else {
            currStartX++;
            currStartY++;
          }
        }

        if (currStartX >= n || currStartY >= m) {
          currStartX--;
          currStartY--;
        }

        int currN = currStartX - startX + 1;
        numSquares += currN;
      }
    }
  }

  return numSquares;
}

void solution()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  cout << countSquares(matrix) << endl;
}

/**
3 4
0 1 1 1
1 1 1 1
0 1 1 1
 */

int main()
{
  solution();

  return 0;
}
