/**
 * 1. DP + Memo - O(n)
 *      Perform DFS on len of curr String
 *      Valid string is when len is [low,high]
 *        Add both decision to count of curr call and return it
 *      Memoize on len param
 */

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int countGoodStrings(int len, int low, int high, int zero, int one, unordered_map<int, int>& dp)
{
  if (len > high) {
    return 0;
  }

  if (dp.find(len) != dp.end()) {
    return dp[len];
  }

  int currCount = 0;

  currCount += (countGoodStrings(len + zero, low, high, zero, one, dp) % MOD);
  currCount += (countGoodStrings(len + one, low, high, zero, one, dp) % MOD);
  currCount %= MOD;

  if (len >= low) {
    currCount += 1;
  }

  dp[len] = currCount;

  return dp[len];
}

int countGoodStrings(int low, int high, int zero, int one)
{
  unordered_map<int, int> dp;
  return countGoodStrings(0, low, high, zero, one, dp);
}

void solution()
{
  int low, high, zero, one;
  cin >> low >> high >> zero >> one;

  cout << countGoodStrings(low, high, zero, one) << endl;
}

int main()
{
  solution();

  return 0;
}
