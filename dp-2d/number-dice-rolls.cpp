#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll numRollsToTarget(int currDie, int n, int k, int target, vector<vector<ll>>& dp)
{
  if (currDie > n) {
    return target == 0;
  }

  if (target < 0) {
    return 0;
  }

  if (dp[currDie][target] != -1) {
    return dp[currDie][target];
  }

  ll numWays = 0;
  for (int i = 1; i <= k; i++) {
    numWays += (numRollsToTarget(currDie + 1, n, k, target - i, dp) % MOD);
  }

  dp[currDie][target] = numWays % MOD;
  return dp[currDie][target];
}

int numRollsToTarget(int n, int k, int target)
{
  vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, -1));

  return numRollsToTarget(1, n, k, target, dp);
}

void solution()
{
  int n, k, target;
  cin >> n >> k >> target;

  cout << numRollsToTarget(n, k, target) << endl;
}

int main()
{
  solution();

  return 0;
}
