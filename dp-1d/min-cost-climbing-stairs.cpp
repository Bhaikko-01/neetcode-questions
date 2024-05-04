#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int>& cost, int currIndex, unordered_map<int, int>& occured)
{
  int n = cost.size();

  if (currIndex >= n) {
    return 0;
  }

  int oneStepCost = minCostClimbingStairs(cost, currIndex + 1, occured);
  int twoStepCost = minCostClimbingStairs(cost, currIndex + 2, occured);

  occured[currIndex] = min(oneStepCost, twoStepCost) + cost[currIndex];

  return occured[currIndex];
}

int minCostClimbingStairs(vector<int>& cost)
{
  unordered_map<int, int> occured;

  return min(minCostClimbingStairs(cost, 0, occured), minCostClimbingStairs(cost, 1, occured));
}

int minCostClimbingStairsDP(vector<int>& cost)
{
  int n = cost.size();

  // ! Each index represents the cost that would be required if we start from there
  vector<int> dp(n + 2);
  dp[n] = 0;
  dp[n + 1] = 0;

  for (int i = n - 1; i >= 0; i--) {
    dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
  }

  return min(dp[0], dp[1]);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  cout << minCostClimbingStairs(cost) << endl;
  cout << minCostClimbingStairsDP(cost) << endl;
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
