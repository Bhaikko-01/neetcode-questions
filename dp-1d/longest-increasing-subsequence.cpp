/**
 * 1. Decision Tree DFS
 *      Consider for every we can create LIS and call recursion based on that
 *      In each call, if nums[i] > nums[currIndex] then we call recursion at that
 *        included = lis(nums, i) + 1
 *        maxLen = max(maxLen, included)
 *          maxLen will be 1 initially as each element is itself LIS of length 1
 *      Memoize on currIndex only
 * 2. DP
 *      Bottom up approach by starting with
 *        n-1 to 0 for i and
 *          j = i+1 to n-1
 *        Check same conditions as in recursion
*/

#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int>& nums, int currIndex, unordered_map<int, int>& occured) {
  int n = nums.size();

  if (occured.find(currIndex) != occured.end()) {
    return occured[currIndex];
  }

  if (currIndex == n - 1) {
    return 1;
  }

  int maxLen = 1;

  for (int i = currIndex; i < n; i++) {
    if (nums[currIndex] < nums[i]) {
      int currLen = lengthOfLIS(nums, i, occured) + 1;

      maxLen = max(currLen, maxLen);
    }
  }

  occured[currIndex] = maxLen;

  return maxLen;
}

int lengthOfLIS(vector<int>& nums) {
  unordered_map<int, int> occured;

  int n = nums.size();

  int maxAns = 1;
  for (int i = 0; i < n; i++) {
    int currAns = lengthOfLIS(nums, i, occured);

    maxAns = max(maxAns, currAns);
  }

  return maxAns;
}

int lengthOfLISDP(vector<int>& nums)
{
  int n = nums.size();

  vector<int> dp(n, 1);

  int maxLen = 1;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] < nums[j]) {
        int currLen = dp[j] + 1;

        dp[i] = max(dp[i], currLen);
      }
    }

    maxLen = max(maxLen, dp[i]);
  }

  return maxLen;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << lengthOfLIS(nums) << endl;
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
