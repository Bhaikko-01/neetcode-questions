/**
 * 1. Decision Tree
 *      rob() method called twice independently where
 *        include first house and dont include last
 *        dont include first house and include last house
 *      To code this, last index is also passed to rob method
 * 2. DP
 *      code considering above decision tree
 *        dont include last element and go till 0th index
 *        include last element and go till 1th index
*/

#include <bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums, int currIndex, int lastIndex, unordered_map<int, int>& occured)
{
  int n = nums.size();

  if (occured.find(currIndex) != occured.end()) {
    return occured[currIndex];
  }

  if (currIndex > lastIndex) {
    return 0;
  }

  int robbedCurrent = rob(nums, currIndex + 2, lastIndex, occured) + nums[currIndex];
  int notRobbedCurrent = rob(nums, currIndex + 1, lastIndex, occured);

  occured[currIndex] = max(robbedCurrent, notRobbedCurrent);

  return occured[currIndex];
}

int rob(vector<int>& nums)
{
  int n = nums.size();

  if (n == 1) {
    return nums[0];
  }

  unordered_map<int, int> occured;

  int firstHouseIncluded = rob(nums, 0, n - 2, occured);

  occured.clear();

  int lastHouseIncluded = rob(nums, 1, n - 1, occured);

  return max(firstHouseIncluded, lastHouseIncluded);
}

int robDp(vector<int>& nums)
{
  int n = nums.size();

  if (n == 1) {
    return nums[0];
  }

  vector<int> dp(n + 1, 0);

  // ! Including first house
  dp[n - 2] = nums[n - 2];

  for (int i = n - 3; i >= 0; i--) {
    int robCurrentHouse = dp[i + 2] + nums[i];
    int notRobCurrentHouse = dp[i + 1];

    dp[i] = max(robCurrentHouse, notRobCurrentHouse);
  }

  int firstHouseIncluded = *max_element(dp.begin(), dp.end());

  // ! Including last house
  dp = vector(n + 1, 0);
  dp[n - 1] = nums[n - 1];

  for (int i = n - 2; i >= 1; i--) {
    int robCurrentHouse = dp[i + 2] + nums[i];
    int notRobCurrentHouse = dp[i + 1];

    dp[i] = max(robCurrentHouse, notRobCurrentHouse);
  }

  int lastHouseIncluded = *max_element(dp.begin(), dp.end());

  return max(firstHouseIncluded, lastHouseIncluded);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << robDp(nums) << endl;
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
