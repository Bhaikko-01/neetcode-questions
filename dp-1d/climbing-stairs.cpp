/**
 * 1. Recursive - O(2^n)
 *      Call recursion using start with start+1 and start+2
 *      Can memoize this if we cache n answer at each recursion call
 * 2. DP - O(n)
 *      Calculate answer for 1 to n and store
 *      for any n, answer is stair(n - 1) + stair(n - 2)
 *      therefore
 *        dp[1] = 1; dp[2] = 2;
 *        dp[i] = dp[i - 1] + dp[i - 2]
 *      return dp[n]
*/
#include <bits/stdc++.h>

using namespace std;

int climbStairs(int start, int n, unordered_map<int, int>& occured)
{
  if (occured[start]) {
    return occured[start];
  }

  if (start > n) {
    return 0;
  }

  if (start == n) {
    return 1;
  }

  int countByOne = climbStairs(start + 1, n, occured);
  int countByTwo = climbStairs(start + 2, n, occured);

  occured[start] = countByOne + countByTwo;

  return countByOne + countByTwo;
}

int climbStairs(int n)
{
  unordered_map<int, int> occured;

  return climbStairs(0, n, occured);
}

int climbStairsDP(int n)
{
  if (n == 1) {
    return 1;
  }

  vector<int> dp(n + 1, 0);

  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

void solution()
{
  int n;
  cin >> n;

  cout << climbStairsDP(n) << endl;
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
