/**
 * 1. Brute Force Backtracking - O(k^n)
 *      Maintain buckets of k and check if we can have all sum as equal
 *      Take decision of currNumber by putting it in each bucket and calling recursive
 *        on updated bucket
 * 2. Optimsed backtraking - O(k*2^n)
 *      Create subsets for target sum till we make k number of subsets
 *      Dont pick element which is already picked
 *      If target is found
 *        if subsetCount == k
 *          return true
 *        else call same recursion with currSum = 0 and occurence updated
 */

#include <bits/stdc++.h>

using namespace std;

// ! 1. Brute Force
bool canPartitionKSubsets(vector<int>& nums, int currIndex, vector<int> sums)
{
  int n = nums.size();
  int k = sums.size();

  if (currIndex == n) {
    for (int i = 0; i < k - 1; i++) {
      if (sums[i] != sums[i + 1]) {
        return false;
      }
    }

    return true;
  }

  bool foundPartition = false;

  for (int i = 0; i < k; i++) {
    sums[i] += nums[currIndex];
    foundPartition = foundPartition || canPartitionKSubsets(nums, currIndex + 1, sums);
    sums[i] -= nums[currIndex];
  }

  return foundPartition;
}

// ! 1. Brute force
// bool canPartitionKSubsets(vector<int>& nums, int k)
// {
//   vector<int> sums(k);
//   return canPartitionKSubsets(nums, 0, sums);
// }

bool canPartitionKSubsets(vector<int>& nums, int currIndex,
                          int currSum, int target,
                          int k,
                          vector<bool>& occured)
{
  int n = nums.size();

  if (k == 0) {
    return true;
  }

  if (currSum == target) {
    return canPartitionKSubsets(nums, 0, 0, target, k - 1, occured);
  }

  if (currIndex >= n) {
    return false;
  }

  int currNum = nums[currIndex];

  if (currNum > target || target < 0) {
    return false;
  }

  bool include = false;

  if (!occured[currIndex]) {
    occured[currIndex] = true;
    include = canPartitionKSubsets(nums, currIndex + 1, currSum + currNum, target, k, occured);

    if (include) {
      return true;
    }

    occured[currIndex] = false;
  }

  return canPartitionKSubsets(nums, currIndex + 1, currSum, target, k, occured);
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
  int sum = 0;
  int n = nums.size();

  vector<bool> occured(n, false);
  for (int num: nums) {
    sum += num;
  }

  if (sum % k != 0) {
    return false;
  }

  int target = sum / k;

  return canPartitionKSubsets(nums, 0, 0, target, k, occured);
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << canPartitionKSubsets(nums, k) << endl;
}

int main()
{
  solution();

  return 0;
}
