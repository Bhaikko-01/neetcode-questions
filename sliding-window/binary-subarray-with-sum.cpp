/**
 * 1. Prefix Sum and Hashing - O(n)
 *      This is similar to subarray sum to k with values always been 0 or 1
 *      https://leetcode.com/problems/subarray-sum-equals-k/description/
*/

#include <bits/stdc++.h>

using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal)
{
  int n = nums.size();

  unordered_map<int, int> prefixSumCount;
  int prefixSum = 0;
  int ans = 0;

  prefixSumCount[0] = 1;

  for (int i = 0; i < n; i++) {
    prefixSum += nums[i];

    int remSum = prefixSum - goal;

    ans += prefixSumCount[remSum];

    prefixSumCount[prefixSum]++;
  }

  return ans;
}

void solution()
{
  int n, goal;
  cin >> n >> goal;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << numSubarraysWithSum(nums, goal) << endl;
}

int main()
{
  solution();

  return 0;
}
