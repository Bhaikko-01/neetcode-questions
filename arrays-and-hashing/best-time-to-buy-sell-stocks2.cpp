/**
 * 1. DP - O(n^2)
 *      Take decisions based on whether it was bought once or not
 *      Return profit based on if it was bought previously or not
 * 2. Find Local maximas - O(n)
 *      We need to find local maximas in adjacent pairs as we can buy and sell indefinetly
 *      If adjacent pair is maxima then add it to profit since we can buy again in future
 *        This will also work for increasing array as each step will yield its profit
 */

#include <bits/stdc++.h>

using namespace std;

string getKey(int first, bool second)
{
  return to_string(first) + "," + to_string(second);
}

int maxProfit(vector<int>& prices, int currIndex, bool allowedToBuy, unordered_map<string, int>& dp)
{
  int n = prices.size();

  string key = getKey(currIndex, allowedToBuy);

  if (currIndex >= n) {
    return 0;
  }

  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  int possibleProfit = 0;

  if (allowedToBuy) {
    possibleProfit = maxProfit(prices, currIndex + 1, false, dp) - prices[currIndex];
  } else {
    possibleProfit = maxProfit(prices, currIndex + 1, true, dp) + prices[currIndex];
  }

  int skippedDay = maxProfit(prices, currIndex + 1, allowedToBuy, dp);

  dp[key] = max(possibleProfit, skippedDay);

  return dp[key];
}

// ! 1.
int maxProfit(vector<int>& prices)
{
  unordered_map<string, int> dp;

  return maxProfit(prices, 0, true, dp);
}

// ! 2.
int maxProfitNonDp(vector<int>& prices)
{
  int n = prices.size();
  int profit = 0;

  for (int i = 0; i < n - 1; i++) {
    if (prices[i] < prices[i + 1]) {
      profit += (prices[i + 1] - prices[i]);
    }
  }

  return profit;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> prices(n);
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  cout << maxProfit(prices) << endl;
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
