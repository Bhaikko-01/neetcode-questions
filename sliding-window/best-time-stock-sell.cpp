/**
 * 1. Brute Force - O(n) [T]
 *    For every pair possible for 0 <= i < n, i < j < n,
 *      maxProfit = max(maxProfit, prices[j] - prices[i])
 * 2. Track min Till current index - O(n) [T]
 *    (Can maintain hash here to maintain minLeftTillNow. O(n) space. To avoid this, use variable instead)
 *    minStockTillNow because we want to maximize (prices[j] - prices[i]) under constaint that i < j.
 *      So we check for minimum value to current Value only
 *    maxProfit = max(maxProfit, prices[i] - minStockTillNow)
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1.
int maxProfitBrute(vector<int>& prices)
{
  int n = prices.size();

  int maxProfit = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      maxProfit = max(maxProfit, prices[j] - prices[i]);
    }
  }

  return maxProfit;
}

// ! 2.
int maxProfit(vector<int>& prices)
{
  int n = prices.size();

  int minStockTillNow = INT_MAX,
      maxStockValue = 0;

  for (int i = 0; i < n; i++) {
    minStockTillNow = min(minStockTillNow, prices[i]);
    maxStockValue = max(maxStockValue, prices[i] - minStockTillNow);
  }

  return maxStockValue;
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
