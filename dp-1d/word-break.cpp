/**
 * 1. Decision Tree - O(2^n)
 *      Decision is taken based on start and end
 *      Base case:
 *        if substring[start:end] exists in wordDict
 *          return true
 *        else
 *          false
 *      If substring between start and end exists in wordDict
 *        call recursion with (currIndex + 1, currIndex + 1)
 *      Always call with (start, currIndex + 1)
 *      return included || notIncluded
 *
 *      Calls in this decision tree can be memoized with start and currIndex
 * 2. DP - O(n^2)
 *      Create DP of start and end
 *      Base case where end is n - 1 and start is from 0 to n-1 is used to fill dp
 *      Bottom UP approach DP is traversed to fill DP
 *      Answer is at dp[0][0] because that represents the starting indexes of start and end
 *        as same in Decision tree
*/

#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

bool wordBreak(string& s, int start, int currIndex, unordered_map<string, bool>& wordDict, unordered_map<string, bool>& occured)
{
  int n = s.size();

  string key = getKey(start, currIndex);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (currIndex == n - 1) {
    string currWord = s.substr(start, currIndex - start + 1);

    return wordDict[currWord];
  }

  string currWord = s.substr(start, currIndex - start + 1);
  bool currWordIncluded = false;
  if (wordDict[currWord]) {
    currWordIncluded = wordBreak(s, currIndex + 1, currIndex + 1, wordDict, occured);
  }

  bool currWordNotIncluded = wordBreak(s, start, currIndex + 1, wordDict, occured);

  occured[key] = currWordIncluded || currWordNotIncluded;

  return occured[key];
}

bool wordBreak(string s, vector<string>& wordDict)
{
  unordered_map<string, bool> wordDictMap;
  for (string word: wordDict) {
    wordDictMap[word] = true;
  }

  unordered_map<string, bool> occured;

  return wordBreak(s, 0, 0, wordDictMap, occured);
}

bool wordBreakDp(string s, vector<string>& wordDict)
{
  unordered_map<string, bool> wordDictMap;
  for (string word: wordDict) {
    wordDictMap[word] = true;
  }

  int n = s.size();

  vector<vector<bool>> dp(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++) {
    string currWord = s.substr(i, n - i);

    dp[i][n - 1] = wordDictMap[currWord];
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      if (i <= j) {
        string currWord = s.substr(i, j - i + 1);

        bool currWordIncluded = false;
        if (wordDictMap[currWord]) {
          currWordIncluded = dp[j + 1][j + 1];
        }

        bool currWordNotIncluded = dp[i][j + 1];

        dp[i][j] = currWordIncluded || currWordNotIncluded;
      }
    }
  }

  return dp[0][0];
}

void solution()
{
  int n;
  cin >> n;

  vector<string> wordDict(n);
  for (int i = 0; i < n; i++) {
    cin >> wordDict[i];
  }

  string s;
  cin >> s;

  cout << wordBreakDp(s, wordDict) << endl;
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
