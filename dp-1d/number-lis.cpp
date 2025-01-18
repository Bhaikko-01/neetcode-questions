/**
 * Intution - Similar to LIS
 *  Along with Length, count of that length is also returned from function call as pair
 *  Decision is taken whether to include current element or not based on previous element added
 *    This element is fetched by using lastNumIndex which
 *      can be -1 indicating that last element is not choosen yet
 *      Hence, lastNum = (lastNumIndex == -1) ? INT_MIN : nums[lastNumIndex]
 *  After both decision values are fetched, check if
 *    returned length is same as maxLen which means, we increase the count
 *    Otherwise, count is just same as returned from function calls. This means, using current element
 *      does not increase the count but only the length max LIS
 *  Function call returns both maxLen and currLisCount
 * 1. DFS + Memoization - O(n^2)
 *    For base case, { 0, 1 } is returned which is
 *      length is 0 and count of length 0 subsequences is 1
 *    After both decisions, check if we need to increase count or keep it unchanged
 *    For memoization, currIndex and lastNumIndex is used for caching
 *
 * 2. DF (Bottom Up) - O(n^2)
 *    2D array of pair is maintained
 *    For this, currIndex is done from [n-1, 0]
 *    For lastNumIndex, some updates are done
 *      it iterates from [-1, currIndex] as we need
 *        case for not choosing any element
 *        lastNumIndex can occur only before currIndex
 *    For storing lastNumIndex values, they are always stored as (j+1) to handle -1 case
 *    Even for currNumIncluded, it uses dp[i+1][i+1] as lastNumIndex are always stored at index+1
 *    Final answer is at dp[0][0] which indicates
 *      starting at 0th index and not choosing any element at start
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

string getKey(int x, int y) {
  return to_string(x) + "," + to_string(y);
}

pp findNumberOfLIS(vector<int>& nums, int i, int lastNumIndex, unordered_map<string, pp>& dp)
{
  int n = nums.size();

  if (i == n) {
    // Returning length = 0 and count = 1
    return { 0, 1 };
  }

  string key = getKey(i, lastNumIndex);

  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  int lastNum = (lastNumIndex == -1) ? INT_MIN : nums[lastNumIndex];

  int maxLen = 0;
  int currLisCount = 0;

  if (nums[i] > lastNum) {
    pp currNumIncludedLis = findNumberOfLIS(nums, i + 1, i, dp);

    maxLen = currNumIncludedLis.first + 1;
    currLisCount = currNumIncludedLis.second;
  }

  pp currNumNotIncludedLis = findNumberOfLIS(nums, i + 1, lastNumIndex, dp);
  int len = currNumNotIncludedLis.first;
  int count = currNumNotIncludedLis.second;

  if (len > maxLen) {
    currLisCount = count;
    maxLen = len;
  } else if (len == maxLen) {
    currLisCount += count;
  }

  dp[key] = { maxLen, currLisCount };

  return dp[key];
}

int findNumberOfLIS2(vector<int>& nums)
{
  unordered_map<string, pp> dp;
  pp ans = findNumberOfLIS(nums, 0, -1, dp);

  return ans.second;
}

int findNumberOfLIS(vector<int>& nums)
{
  int n = nums.size();

  vector<vector<pp>> dp(n + 1, vector<pp>(n + 1));

  for (int i = 0; i <= n; i++) {
    dp[n][i] = { 0, 1 };
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = -1; j < i; j++) {
      int lastNum = (j == -1) ? INT_MIN : nums[j];

      int maxLen = 0;
      int currLisCount = 0;

      if (nums[i] > lastNum) {
        pp currNumIncludedLis = dp[i + 1][i + 1];

        maxLen = currNumIncludedLis.first + 1;
        currLisCount = currNumIncludedLis.second;
      }

      pp currNumNotIncludedLis = dp[i + 1][j + 1];
      int len = currNumNotIncludedLis.first;
      int count = currNumNotIncludedLis.second;

      if (len > maxLen) {
        currLisCount = count;
        maxLen = len;
      } else if (len == maxLen) {
        currLisCount += count;
      }

      dp[i][j + 1] = { maxLen, currLisCount };
    }
  }

  return dp[0][0].second;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << findNumberOfLIS(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
