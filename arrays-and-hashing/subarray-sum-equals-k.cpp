/**
 * 1. Brute Force - O(n^2)
 *      Generate all subarrays and find sum
 *      increase count if subarray sum matches k
 * 2. Prefix sum - O(n)
 *      Maintain prefix sum till each index as we traverse array
 *      Maintain sum and find if (sum - k) has already occured as prefix sum
 *        If it has occured then count += prefixSumCount[sum - k]
 *      Make sure to add prefixSum to hashmap after processing count as we should not remove current element
 */

#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k)
{
  int n = nums.size();

  unordered_map<int, int> prefixSumCountMapping;
  int sum = 0,
      count = 0;

  prefixSumCountMapping[0] = 1;

  for (int i = 0; i < n; i++) {
    sum += nums[i];

    int requiredPrefixSumToRemove = sum - k;

    count += prefixSumCountMapping[requiredPrefixSumToRemove];

    prefixSumCountMapping[sum]++;
  }

  return count;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << subarraySum(nums, k) << endl;
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
