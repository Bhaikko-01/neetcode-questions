/**
 * 1. Decision tree
 *      Take decision based on amount
 *      Increment final count if aomunt reaches 0
 *        includeWays = change(amount - coins[currIndex], currIndex)
 *        dontIncludeWays = change(amount, currIndex + 1)
 *      ans = includeWays + dontIncludeWays
 *    Memoization: cache currIndex and amount
 * 2. DP - Bottom Up
 *      Do same as recursion calls
 *      Base case
 *        dp[0][i] = 1 // 1 way by every coin to make up amount=0
 *      ans = dp[amount][0] // Signifies, calculating whole amount and starting from index 0
*/

#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

int change(vector<int>& coins, int amount, int currIndex, unordered_map<string, int>& occured)
{
  int n = coins.size();
  string key = getKey(currIndex, amount);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (amount == 0) {
    return 1;
  }

  if (amount < 0) {
    return 0;
  }

  if (currIndex >= n) {
    return 0;
  }

  int includeCount = change(coins, amount - coins[currIndex], currIndex, occured);
  int dontIncludeCount = change(coins, amount, currIndex + 1, occured);

  occured[key] = includeCount + dontIncludeCount;
  return occured[key];
}

int change(int amount, vector<int>& coins)
{
  unordered_map<string, int> occured;

  return change(coins, amount, 0, occured);
}

int changeDP(int amount, vector<int>& coins)
{
  int n = coins.size();

  vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 0));
  // ! This implies, we can create amount=0 by 1 way using coin at index i
  for (int i = 0; i < n; i++) {
    dp[0][i] = 1;
  }

  for (int i = 1; i <= amount; i++) {
    for (int j = n - 1; j >= 0; j--) {
      int includeCount = 0;
      int remAmount = i - coins[j];

      if (remAmount >= 0) {
        includeCount = dp[remAmount][j];
      }

      int notIncludedCount = dp[i][j + 1];

      dp[i][j] = includeCount + notIncludedCount;
    }
  }

  return dp[amount][0];
}

void solution()
{
  int n, amount;
  cin >> n >> amount;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  cout << changeDP(amount, coins) << endl;
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
