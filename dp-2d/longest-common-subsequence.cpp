/**
 * 1. Decision Tree
 *      Maintain currIndex1 and currIndex2 for text1 and text1
 *      If text1[currIndex1] == text2[currIndex2]
 *        call recursion with currIndex1 + 1 and currIndex2 + 1
 *      Else
 *        return max(currIndex1 + 1, currIndex2 + 1)
*/

#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

int longestCommonSubsequence(string& text1, string& text2, int currIndex1, int currIndex2, unordered_map<string, int>& occured)
{
  int m = text1.size();
  int n = text2.size();

  string key = getKey(currIndex1, currIndex2);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (currIndex1 >= m || currIndex2 >= n) {
    return 0;
  }

  if (text1[currIndex1] == text2[currIndex2]) {
    occured[key] = 1 + longestCommonSubsequence(text1, text2, currIndex1 + 1, currIndex2 + 1, occured);
    return occured[key];
  }

  int skipFirst = longestCommonSubsequence(text1, text2, currIndex1 + 1, currIndex2, occured);
  int skipSecond = longestCommonSubsequence(text1, text2, currIndex1, currIndex2 + 1, occured);

  occured[key] = max(skipFirst, skipSecond);
  return occured[key];
}

int longestCommonSubsequence(string text1, string text2)
{
  unordered_map<string, int> occured;

  return longestCommonSubsequence(text1, text2, 0, 0, occured);
}

int longestCommonSubsequenceDP(string text1, string text2)
{
  int m = text1.size();
  int n = text2.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < m; i++) {
    dp[i][n] = 0;
  }

  for (int i = 0; i < n; i++) {
    dp[m][i] = 0;
  }

  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (text1[i] == text2[j]) {
        dp[i][j] = 1 + dp[i + 1][j + 1];
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  return dp[0][0];
}

void solution()
{
  string text1, text2;
  cin >> text1 >> text2;

  cout << longestCommonSubsequenceDP(text1, text2) << endl;
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
