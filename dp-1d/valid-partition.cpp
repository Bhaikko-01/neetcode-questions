#include <bits/stdc++.h>

using namespace std;

bool isValidSubarray(vector<int>& nums, int start, int end)
{
  if (end >= nums.size()) {
    return false;
  }

  int len = end - start + 1;

  if (len <= 1 || len >= 4) {
    return false;
  }

  if (len == 2) {
    return nums[start] == nums[end];
  }

  if (len == 3) {
    return nums[start] == nums[start + 1] && nums[start + 1] == nums[end] ||
           nums[start] + 1 == nums[start + 1] && nums[start + 1] + 1 == nums[end];
  }

  return false;
}

bool validPartition(vector<int>& nums, int currIndex, unordered_map<int, bool>& occured)
{
  int n = nums.size();

  if (currIndex == n) {
    return true;
  }

  if (currIndex > n) {
    return false;
  }

  if (occured.find(currIndex) != occured.end()) {
    return occured[currIndex];
  }

  bool ans = false;

  for (int i = 1; i <= 2; i++) {
    int currEnd = currIndex + i;

    if (isValidSubarray(nums, currIndex, currEnd)) {
      ans = ans || validPartition(nums, currEnd + 1, occured);
    }
  }

  occured[currIndex] = ans;

  return occured[currIndex];
}

bool validPartition(vector<int>& nums)
{
  unordered_map<int, bool> occured;

  return validPartition(nums, 0, occured);
}

bool validPartitionDP(vector<int>& nums)
{
  int n = nums.size();

  vector<bool> dp(n + 1, false);
  dp[n] = true;

  for (int i = n - 1; i >= 0; i--) {
    bool ans = false;

    for (int j = 1; j <= 2; j++) {
      int currEnd = i + j;

      if (isValidSubarray(nums, i, currEnd)) {
        ans = ans || dp[currEnd + 1];
      }
    }

    dp[i] = ans;
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

  cout << validPartitionDP(nums) << endl;
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
