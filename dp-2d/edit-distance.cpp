/**
 * 1. Decision Tree
 *      If word1[currIndex1] == word2[currIndex2]
 *        no need to do any operation, move ahead
 *      Else (operations are done on first string)
 *        insert: (i, j + 1)
 *          character will be inserted before current position so no need to move word1 ahead
 *          move word2 ahead only
 *        delete: (i + 1, j)
 *          character will be deleted at current index so ned to move ahead
 *        relace: (i + 1, j + 1)
 *          assuming we place correct character, we move ahead both pointers
*/

#include <bits/stdc++.h>

using namespace std;

string getKey(int x, int y)
{
  return to_string(x) + "," + to_string(y);
}

int minDistance(string& word1, string& word2, int currIndex1, int currIndex2, unordered_map<string, int>& occured)
{
  int m = word1.size();
  int n = word2.size();

  string key = getKey(currIndex1, currIndex2);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (currIndex1 == m && currIndex2 == n) {
    return 0;
  }

  // ! If currIndex1 is reached end and word2 is still left
  // ! then we just delete all those character. Hence n - currIndex2 operations
  if (currIndex1 == m) {
    // ! +1 not done as n is length not last index so +1 already included in n
    return n - currIndex2;
  }

  if (currIndex2 == n) {
    return m - currIndex1;
  }

  if (word1[currIndex1] == word2[currIndex2]) {
    return minDistance(word1, word2, currIndex1 + 1, currIndex2 + 1, occured);
  }

  int insertChar = minDistance(word1, word2, currIndex1, currIndex2 + 1, occured);
  int deleteChar = minDistance(word1, word2, currIndex1 + 1, currIndex2, occured);
  int replaceChar = minDistance(word1, word2, currIndex1 + 1, currIndex2 + 1, occured);

  occured[key] = min(insertChar, min(deleteChar, replaceChar)) + 1;
  return occured[key];
}

int minDistance(string word1, string word2)
{
  int m = word1.size();
  int n = word2.size();

  unordered_map<string, int> occured;

  if (m < n) {
    return minDistance(word2, word1, 0, 0, occured);
  }

  return minDistance(word1, word2, 0, 0, occured);
}

int minDistanceDp(string word1, string word2)
{
  int m = word1.size();
  int n = word2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
  dp[m][n] = 0;

  for (int i = 0; i < m; i++) {
    dp[i][n] = m - i;
  }

  for (int i = 0; i < n; i++) {
    dp[m][i] = n - i;
  }

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (word1[i] == word2[j]) {
        dp[i][j] = dp[i + 1][j + 1];
      } else {
        int insertChar = dp[i][j + 1];
        int deleteChar = dp[i + 1][j];
        int replaceChar = dp[i + 1][j + 1];

        dp[i][j] = min(insertChar, min(deleteChar, replaceChar)) + 1;
      }
    }
  }

  return dp[0][0];
}

void solution()
{
  string word1, word2;
  cin >> word1 >> word2;

  cout << minDistanceDp(word1, word2) << endl;
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
