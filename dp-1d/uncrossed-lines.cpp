/**
 * Intution
 *  Choose number in one direction only from nums2 while considering every element from nums1
 *    Take decision only when nums1[currIndex] == nums2[j], where [numsLastCutIndex, m-1]
 *    Also Consider when no number is choosen from nums2, simply passing numsLastCutIndex in subsequent calls
 *    max of above all is answer
 *
 * 1. DFS + Memoization - O(n^2)
 *      Base case is if any index goes out of bounds
 *      Take decision for valid matches and no choice from nums2
 *      Max of all above is answer
 * 2. DP - O(n^2)
 *      Run iteration from [n-1,0] and [m-1,0]
 *      Decision is same as above
 *      Final ans is dp[0][0] which means, best answer when both array started from 0
 */

#include <bits/stdc++.h>

using namespace std;

string getKey(int a, int b) {
  return to_string(a) + "," + to_string(b);
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2, int nums1Index, int nums2LastCutIndex, unordered_map<string, int>& dp)
{
  int n = nums1.size(),
      m = nums2.size();

  if (nums1Index >= n || nums2LastCutIndex >= m) {
    return 0;
  }

  string key = getKey(nums1Index, nums2LastCutIndex);

  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  int maxCount = 0;
  for (int j = nums2LastCutIndex; j < m; j++) {
    if (nums1[nums1Index] == nums2[j]) {
      int currCount = maxUncrossedLines(nums1, nums2, nums1Index + 1, j + 1, dp) + 1;
      maxCount = max(maxCount, currCount);
    }
  }

  int ignoreAllCount = maxUncrossedLines(nums1, nums2, nums1Index + 1, nums2LastCutIndex, dp);
  maxCount = max(maxCount, ignoreAllCount);

  dp[key] = maxCount;

  return dp[key];
}

int maxUncrossedLinesMemo(vector<int>& nums1, vector<int>& nums2)
{
  unordered_map<string, int> dp;

  return maxUncrossedLines(nums1, nums2, 0, 0, dp);
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
{
  int n = nums1.size();
  int m = nums2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = n - 1; i >= 0; i--) {
    int maxCount = 0;
    for (int j = m - 1; j >= 0; j--) {
      if (nums1[i] == nums2[j]) {
        int currCount = dp[i + 1][j + 1] + 1;

        maxCount = max(maxCount, currCount);
      }

      maxCount = max(maxCount, dp[i + 1][j]);

      dp[i][j] = maxCount;
    }
  }

  return dp[0][0];
}

void solution()
{
  int n, m;
  cin >> n >> m;

  vector<int> nums1(n), nums2(m);
  for (int i = 0; i < n; i++) {
    cin >> nums1[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> nums2[i];
  }

  cout << maxUncrossedLines(nums1, nums2) << endl;
}

int main()
{
  solution();

  return 0;
}
