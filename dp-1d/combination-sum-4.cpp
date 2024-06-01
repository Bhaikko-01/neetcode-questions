#include <bits/stdc++.h>

using namespace std;

int combinationSum4(vector<int>& nums, int target, unordered_map<int, int>& occured)
{
  int n = nums.size();

  if (target < 0) {
    return 0;
  }

  if (target == 0) {
    return 1;
  }

  if (occured.find(target) != occured.end()) {
    return occured[target];
  }

  int possibleWays = 0;
  for (int num: nums) {
    possibleWays += combinationSum4(nums, target - num, occured);
  }

  occured[target] = possibleWays;

  return occured[target];
}

int combinationSum4(vector<int>& nums, int target)
{
  unordered_map<int, int> occured;

  return combinationSum4(nums, target, occured);
}

int combinationSum4Dp(vector<int>& nums, int target)
{
  int n = nums.size();

  vector<unsigned int> dp(target + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= target; i++) {
    int possibleWays = 0;

    for (int num: nums) {
      int newTarget = i - num;

      if (newTarget >= 0) {
        possibleWays += dp[newTarget];
      }
    }

    dp[i] = possibleWays;
  }

  return dp[target];
}

void solution()
{
  int n, target;
  cin >> n >> target;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << combinationSum4Dp(nums, target) << endl;
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
