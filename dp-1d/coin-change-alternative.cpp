#include <bits/stdc++.h>

using namespace std;

int coinChangeHelper(vector<int>& coins, int amount, unordered_map<int, int>& dp)
{
  int n = coins.size();

  if (dp.find(amount) != dp.end()) {
    return dp[amount];
  }

  if (amount == 0) {
    return 0;
  }

  if (amount < 0) {
    return INT_MAX;
  }

  int minWays = INT_MAX;

  for (int i = 0; i < n; i++) {
    int currWays = coinChangeHelper(coins, amount - coins[i], dp);

    if (currWays == INT_MAX) {
      continue;
    }

    minWays = min(minWays, currWays + 1);
  }

  dp[amount] = minWays;

  return dp[amount];
}

// int coinChange(vector<int>& coins, int amount)
// {
//   unordered_map<int, int> dp;
//   int ans = coinChangeHelper(coins, amount, dp);

//   return ans == INT_MAX ? -1 : ans;
// }

int coinChange(vector<int>& coins, int amount)
{
  int n = coins.size();

  vector<int> dp(amount + 1);
  dp[0] = 0;

  for (int i = 1; i <= amount; i++) {
    int minWays = INT_MAX;

    for (int j = n - 1; j >= 0; j--) {
      int remAmount = i - coins[j];
      if (remAmount >= 0) {
        int currWays = dp[remAmount];

        if (currWays == INT_MAX) {
          continue;
        }

        minWays = min(minWays, currWays + 1);
      }
    }

    dp[i] = minWays;
  }

  return dp[amount] == INT_MAX ? -1 : dp[amount];
}

void solution()
{
  int n, amount;
  cin >> n >> amount;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  cout << coinChange(coins, amount) << endl;
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
