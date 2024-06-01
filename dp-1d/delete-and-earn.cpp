#include <bits/stdc++.h>

using namespace std;

int deleteAndEarn(vector<int>& nums, int currIndex, unordered_map<int, int>& numOccurences, unordered_map<int, int>& dp)
{
  int n = nums.size();

  if (currIndex >= n) {
    return 0;
  }

  if (currIndex == n - 1) {
    return nums[currIndex];
  }

  if (dp.find(currIndex) != dp.end()) {
    return dp[currIndex];
  }

  int num = nums[currIndex];

  int nextGreaterIndex = currIndex + 1;
  while (nextGreaterIndex < n && nums[nextGreaterIndex] == nums[currIndex]) {
    nextGreaterIndex++;
  }

  int notDeleted = deleteAndEarn(nums, nextGreaterIndex, numOccurences, dp);

  if (nums[nextGreaterIndex] == nums[currIndex] + 1) {
    int newIndex = nextGreaterIndex;
    while (nextGreaterIndex < n && nums[nextGreaterIndex] == nums[newIndex]) {
      nextGreaterIndex++;
    }
  }

  int deleted = deleteAndEarn(nums, nextGreaterIndex, numOccurences, dp) + numOccurences[num] * num;

  dp[currIndex] = max(notDeleted, deleted);

  return dp[currIndex];
}

int deleteAndEarn(vector<int>& nums)
{
  sort(nums.begin(), nums.end());

  unordered_map<int, int> numOccurences;
  unordered_map<int, int> dp;
  for (int num: nums) {
    numOccurences[num]++;
  }

  return deleteAndEarn(nums, 0, numOccurences, dp);
}

int deleteAndEarnDP(vector<int>& nums)
{
  int n = nums.size();

  sort(nums.begin(), nums.end());

  unordered_map<int, int> numOccurences;
  for (int num: nums) {
    numOccurences[num]++;
  }

  vector<int> dp(n + 1);
  dp[n] = 0;
  dp[n - 1] = nums[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    int num = nums[i];

    int nextGreaterIndex = i + 1;
    while (nextGreaterIndex < n && nums[nextGreaterIndex] == nums[i]) {
      nextGreaterIndex++;
    }

    int notDeleted = dp[nextGreaterIndex];

    if (nums[nextGreaterIndex] == nums[i] + 1) {
      int newIndex = nextGreaterIndex;
      while (nextGreaterIndex < n && nums[nextGreaterIndex] == nums[newIndex]) {
        nextGreaterIndex++;
      }
    }

    int deleted = dp[nextGreaterIndex] + numOccurences[num] * num;

    dp[i] = max(notDeleted, deleted);
  }

  return dp[0];
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << deleteAndEarnDP(nums) << endl;
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
