#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int rangeSum(vector<int>& nums, int n, int left, int right)
{
  vector<int> subarraySums;

  for (int i = 0; i < n; i++) {
    int currSum = 0;

    for (int j = i; j < n; j++) {
      currSum += nums[j];

      subarraySums.push_back(currSum);
    }
  }

  sort(subarraySums.begin(), subarraySums.end());

  int ans = 0;

  for (int i = left - 1; i < right; i++) {
    ans = (ans + subarraySums[i]) % MOD;
  }

  return ans;
}

void solution()
{
  int n, left, right;
  cin >> n >> left >> right;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << rangeSum(nums, n, left, right) << endl;
}

int main()
{
  solution();

  return 0;
}
