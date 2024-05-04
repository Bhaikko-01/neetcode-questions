/**
 * 1. Decision Tree - O(2^n)
 *      For each index, we have two decision to take if they fullfill condition
 *        index+1 if s[currIndex] != '0' then we call recursion with index+1
 *        index+2 if
 *          currLen of subString using currIndex is greater than 2 AND
 *          s[currIndex, 2] lies between 10 and 26 then we call recursion with index+2
 *      If currIndex == n, then we have possible grouping, count++;
 * 2. Memoize Above - O(n)
 *      cache will store the `count` for each index when it is processed
 *      If currIndex exists in cache then we
 *        return count += cache[currIndex]
 *      This works because, if in future we reach the same index we have calculated in past
 *        then totalCount for current would be pastCount + count calculated till now
 *        += because our current grouping will be different for same past count
 * 3. DP - O(n)
 *      DP of size n + 1 is considered where dp[n] = 0 as for our base case
 *        empty string has one way we can group it
 *      Instead of using count, dp[i] is updated directly
 *        rest of the substring code remains same
 *    Note: Two variables can be used instead of whole cache array
*/

#include <bits/stdc++.h>

using namespace std;

void numDecodings(string& s, int currIndex, int& count, unordered_map<int, int>& occured)
{
  int n = s.size();

  if (occured[currIndex]) {
    count += occured[currIndex];
    return;
  }

  if (currIndex > n) {
    return;
  }

  if (currIndex == n) {
    count++;
    return;
  }

  string considerFirst = s.substr(currIndex, 1);
  int converted = stoi(considerFirst);

  int considerFirstWays = 0;
  if (converted != 0) {
    numDecodings(s, currIndex + 1, count, occured);
  }

  if (currIndex > n - 1) {
    return;
  }

  string considerFirstTwo = s.substr(currIndex, 2);
  int convertedFirstTwo = stoi(considerFirstTwo);

  if (convertedFirstTwo >= 10 && convertedFirstTwo <= 26) {
    numDecodings(s, currIndex + 2, count, occured);
  }

  occured[currIndex] = count;
}

int numDecodings(string s)
{
  unordered_map<int, int> occured;
  int ans = 0;

  numDecodings(s, 0, ans, occured);

  return ans;
}

int numDecodingsDp(string s)
{
  int n = s.size();

  vector<int> dp(n + 1, 0);

  dp[n] = 1;

  for (int i = n - 1; i >= 0; i--) {
    string considerFirst = s.substr(i, 1);
    int converted = stoi(considerFirst);

    int considerFirstWays = 0;
    if (converted != 0) {
      dp[i] += dp[i + 1];
    }

    if (i > n - 1) {
      continue;
    }

    string considerFirstTwo = s.substr(i, 2);
    int convertedFirstTwo = stoi(considerFirstTwo);

    if (convertedFirstTwo >= 10 && convertedFirstTwo <= 26) {
      dp[i] += dp[i + 2];
    }
  }

  return dp[0];
}

void solution()
{
  string s;
  cin >> s;

  cout << numDecodingsDp(s) << endl;
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
