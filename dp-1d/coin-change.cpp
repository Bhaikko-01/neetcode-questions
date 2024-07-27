/**
 * 1. Backtracking
 *      TOP TO BOTTOM APPROACH
 *      Take decision based on current coin.
 *        If currCoin is picked then call recursion with decreased amount
 *        If currCoin is not picked then call recursion with next index without decreased amount
 *      ans for curr index would be min(included, notIncluded)
 * 2. Memoize
 *      Need to memoize both amount and index
 *        amount will signify if we have solved for this amount down the tree
 *        index will represent if we have solved for an amount when elements
 *          from this index to end are included
 * 3. DP
 *      BOTTOM UP APPROACH
 *      Create DP that would track both amount and index
 *      add base cases to DP and iterate
 *      dp[amount][0] is ans as it signifies that for amount and elements from 0th index included
 * NOTE: At every iteration, we can just include all amount of array and call recursion on decreased amount
 *        This way, we dont need to memoize index but only amount
*/

#include <bits/stdc++.h>

using namespace std;

string generateKey(int amount, int currIndex)
{
  return to_string(amount) + "," + to_string(currIndex);
}

int coinChange(vector<int>& coins, int currIndex, int amount, unordered_map<string, int>& occured)
{
  string key = generateKey(amount, currIndex);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (amount < 0) {
    return -1;
  }

  if (amount == 0) {
    return 0;
  }

  int n = coins.size();
  if (currIndex >= n) {
    return -1;
  }

  int includeCurr = coinChange(coins, currIndex, amount - coins[currIndex], occured);
  if (includeCurr != -1) {
    includeCurr++;
  }

  int notIncludeCurr = coinChange(coins, currIndex + 1, amount, occured);

  if (includeCurr == -1) {
    occured[key] = notIncludeCurr;
    return occured[key];
  }

  if (notIncludeCurr == -1) {
    occured[key] = includeCurr;
    return occured[key];
  }

  occured[key] = min(includeCurr, notIncludeCurr);
  return occured[key];
}

int coinChange(vector<int>& coins, int amount)
{
  unordered_map<string, int> occured;

  return coinChange(coins, 0, amount, occured);
}

int coinChangeDP(vector<int>& coins, int amount)
{
  int n = coins.size();

  vector<vector<int>> dp(amount + 1, vector<int>(n + 1, INT_MAX));

  // zero coins needed for amount zero
  for (int i = 0; i < n; i++) {
    dp[0][i] = 0;
  }

  // Out of index base case all amount
  for (int i = 1; i <= amount; i++) {
    dp[i][n] = INT_MAX;
  }

  for (int currAmount = 1; currAmount <= amount; currAmount++) {
    for (int i = n - 1; i >= 0; i--) {
      int includeCurr = INT_MAX;

      int remAmount = currAmount - coins[i];

      if (remAmount >= 0 && dp[remAmount][i] != INT_MAX) {
        includeCurr = dp[remAmount][i] + 1;
      }

      int notIncludeCurr = dp[currAmount][i + 1];

      dp[currAmount][i] = min(includeCurr, notIncludeCurr);
    }
  }

  return dp[amount][0] == INT_MAX ? -1 : dp[amount][0];
}

void solution()
{
  int n, amount;
  cin >> n >> amount;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  cout << coinChangeDP(coins, amount) << endl;
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
