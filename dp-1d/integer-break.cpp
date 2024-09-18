#include <bits/stdc++.h>

using namespace std;

int integerBreak(int n, unordered_map<int, int>& dp)
{
  if (n == 1) {
    return 1;
  }

  if (n == 2) {
    return 1;
  }

  if (dp.find(n) != dp.end()) {
    return dp[n];
  }

  int currMax = INT_MIN;

  for (int i = 1; i < n; i++) {
    int possibleMax = i * (n - i);
    int possibleRecMax = i * integerBreak(n - i, dp);

    currMax = max(currMax, max(possibleMax, possibleRecMax));
  }

  dp[n] = currMax;
  return dp[n];
}

int integerBreak(int n)
{
  unordered_map<int, int> dp;

  return integerBreak(n, dp);
}

void solution()
{
  int n;
  cin >> n;

  cout << integerBreak(n) << endl;
}

int main()
{
  solution();

  return 0;
}
