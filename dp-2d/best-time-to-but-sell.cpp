/**
 * 1. Decision Tree
 *      Take decision based on currIndex and if previously bought/sold
 *      Each iteration have two decision based on previous decision
 *        if bought previously
 *          sell: profit = maxProfit(currIndex + 2, false) + prices[currIndex]
 *          doNothing: profit = maxProfit(currIndex + 1, previousDecision)
 *        if sold previously
 *          buy: profit = maxProfit(currIndex + 1, true) + prices[currIndex]
 *          doNothing: profit = maxProfit(currIndex + 1, previousDecision)
 *        return max(sell, buy, doNothing)
 *      Memoize on currIndex and previousDecision
 * 2. DP - Bottom up
 *      Pretty much same decision as in Decision tree
 *      dp will have indexes as row and decision as column
 *      return dp[0][0], this implies start with 0 index and never bought before
*/

#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

int maxProfit(vector<int>& prices, int currIndex, bool boughtBefore, unordered_map<string, int>& occured)
{
  int n = prices.size();
  string key = getKey(currIndex, boughtBefore);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (currIndex >= n) {
    return 0;
  }

  // Never bought / sold before
  int boughtAtCurrent = INT_MIN;
  if (!boughtBefore) {
    boughtAtCurrent = maxProfit(prices, currIndex + 1, true, occured) - prices[currIndex];
  }

  // Selling
  int soldAtCurrent = INT_MIN;
  if (boughtBefore) {
    soldAtCurrent = maxProfit(prices, currIndex + 2, false, occured) + prices[currIndex];
  }

  // Skip
  int noDecision = maxProfit(prices, currIndex + 1, boughtBefore, occured);

  occured[key] = max(noDecision, max(boughtAtCurrent, soldAtCurrent));

  return occured[key];
}

int maxProfit(vector<int>& prices)
{
  unordered_map<string, int> occured;

  return maxProfit(prices, 0, false, occured);
}

int maxProfitDP(vector<int>& prices)
{
  int n = prices.size();

  vector<vector<int>> dp(n + 2, vector<int>(2, INT_MIN));
  dp[n][0] = 0;
  dp[n][1] = 0;
  dp[n + 1][0] = 0;
  dp[n + 1][1] = 0;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      int boughtAtCurrent = INT_MIN;

      if (!j) {
        boughtAtCurrent = dp[i + 1][1] - prices[i];
      }

      int soldAtCurrent = INT_MIN;
      if (j) {
        soldAtCurrent = dp[i + 2][0] + prices[i];
      }

      int noDecision = dp[i + 1][j];

      dp[i][j] = max(
        noDecision,
        max(boughtAtCurrent, soldAtCurrent)
      );
    }
  }

  return dp[0][0];
}

void solution()
{
  int n;
  cin >> n;

  vector<int> prices(n);
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  cout << maxProfitDP(prices) << endl;
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
