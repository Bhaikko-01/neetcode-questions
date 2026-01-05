/**
 * 1. Backtracking - O(2^n)
 *      - Take decision based on current book to place it
 *        -- On same shelf if possible to place by comparing width possible
 *        -- On next shelf
 *      placeAdjacent = If on same shelf, then check maxHeight for that level and update if new height is more
 *      placeTop = If on next shelf, simply place it + maxOfCurrShelf
 *      return min(placeAdjacent, placeTop)
 */

#include <bits/stdc++.h>

using namespace std;

string getKey(int x, int y, int z) {
  return to_string(x) + "," + to_string(y) + "," + to_string(z);
}

int minHeightShelves(
  vector<vector<int>>& books, int currIndex,
  int leftStart, int maxHeightForCurrLevel,
  int shelfWidth,
  unordered_map<string, int>& occured
) {
  int n = books.size();

  string key = getKey(currIndex, leftStart, maxHeightForCurrLevel);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (currIndex == n) {
    return maxHeightForCurrLevel;
  }

  int currWidth = books[currIndex][0];
  int currHeight = books[currIndex][1];

  int placeAdjacent = INT_MAX;
  if (leftStart + currWidth <= shelfWidth) {
    int newHeight = max(maxHeightForCurrLevel, currHeight);

    placeAdjacent = minHeightShelves(books, currIndex + 1, leftStart + currWidth, newHeight, shelfWidth, occured);
  }

  int placeTop = minHeightShelves(books, currIndex + 1, currWidth, currHeight, shelfWidth, occured) + maxHeightForCurrLevel;

  occured[key] = min(placeAdjacent, placeTop);

  return occured[key];
}

int minHeightShelvesX(vector<vector<int>>& books, int shelfWidth)
{
  unordered_map<string, int> occured;

  return minHeightShelves(
    books,
    0, 0, 0,
    shelfWidth,
    occured
  );
}

int minHeightShelves(vector<vector<int>>& books, int shelfWidth)
{
  int n = books.size();

  int maxHeight = 0;
  for (vector<int>& book: books) {
    maxHeight += book[1];
  }

  vector<vector<vector<int>>> dp(
    n + 1, vector<vector<int>>(
      shelfWidth + 1, vector<int>(
        maxHeight + 1, -1
      )
    )
  );

  for (int i = n; i >= 0; i--) {
    for (int j = shelfWidth; j >= 0; j--) {
      for (int k = maxHeight; k >= 0; k--) {
        if (i == n) {
          dp[i][j][k] = k;
        } else {
          int currWidth = books[i][0];
          int currHeight = books[i][1];

          int placeAdjacent = INT_MAX;
          if (j + currWidth <= shelfWidth) {
            int newHeight = max(k, currHeight);

            placeAdjacent = dp[i + 1][j + currWidth][newHeight];
          }

          int placeTop = dp[i + 1][currWidth][currHeight] + k;

          dp[i][j][k] = min(placeAdjacent, placeTop);
        }
      }
    }
  }

  return dp[0][0][0];
}

/**
 *
7
1 1
2 3
2 3
1 1
1 1
1 1
1 2
4
 */

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> books(n, vector<int>(2));

  for (int i = 0; i < n; i++) {
    cin >> books[i][0] >> books[i][1];
  }

  int shelfWidth;
  cin >> shelfWidth;

  cout << minHeightShelves(books, shelfWidth) << endl;
}

int main()
{
  solution();

  return 0;
}
