/**
 * 1. Brute Force - O(n^3) [T], O(n^2) [S]
 *      Generate all subarrays - O(n^2)
 *      For each subset, generate sum and check max - O(n)
 * 2. Kadane Algo - O(n)
 *      Maintain sumTillNow which contains sum Till current index
 *      Check if sumTillNow is maximum
 *        if yes then that is max subarray sum
 *      If sumTillnow reaches less than 0,
 *        reset it to zero
*/

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums)
{
  int maxSum = INT_MIN;
  int maxSumTillNow = 0;

  for (int x: nums) {
    maxSumTillNow += x;

    maxSum = max(maxSum, maxSumTillNow);

    if (maxSumTillNow < 0) {
      maxSumTillNow = 0;
    }
  }

  return maxSum;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxSubArray(nums) << endl;
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
