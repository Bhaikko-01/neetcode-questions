#include <bits/stdc++.h>

using namespace std;

int numSquares(int n, int currSum, unordered_map<int, int>& occured)
{
  if (occured.find(currSum) != occured.end()) {
    return occured[currSum];
  }

  if (currSum > n) {
    return INT_MAX;
  }

  if (currSum == n) {
    return 0;
  }

  int ans = INT_MAX;

  for (int i = 1; i <= n / 2 + 1; i++) {
    int currAns = numSquares(n, currSum + i * i, occured);

    if (currAns != INT_MAX) {
      ans = min(ans, currAns + 1);
    }
  }

  occured[currSum] = ans;

  return occured[currSum];
}

int numSquares(int n)
{
  unordered_map<int, int> occured;
  return numSquares(n, 0, occured);
}

int numSquaredDp(int n)
{
  vector<int> dp(n + 1, INT_MAX);
  dp[n] = 0;

  for (int currSum = n - 1; currSum >= 0; currSum--) {
    int ans = INT_MAX;

    for (int i = 1; i * i <= n; i++) {
      int newSum = currSum + i * i;

      if (newSum <= n) {
        int currAns = dp[newSum];

        if (currAns != INT_MAX) {
          ans = min(ans, currAns + 1);
        }
      }
    }

    dp[currSum] = ans;
  }

  return dp[0];
}

void solution()
{
  int n;
  cin >> n;

  cout << numSquaredDp(n) << endl;
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
