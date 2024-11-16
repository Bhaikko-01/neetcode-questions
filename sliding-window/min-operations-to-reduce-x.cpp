/**
 * 1. Backtracking and DP - O(n^2)
 *      Take decision on l and r pointer.
 * 2. Prefix and Postfix sum - O(n^2)
 *      Try every possible pair of prefix and postfix sum
 *      Ans is minimum possible out of all combinations
 * 3. Sliding Window - O(n)
 *      Instead of finding edge sums, find subarray whose sum is (arrSun - x)
 *        This would mean we found a subarray in middle whose sum is (arrSum - x)
 *        So sum at edges will be x
 *      ans = min(n - lenSubArry, ans)
 *      Use sliding window to find subarray with a specific sum in middle
 *      Note: x cannot be greater than arrSum. In this case, simply return -1
 */

#include <bits/stdc++.h>

using namespace std;

// ! 1.
int minOperations(vector<int>& nums, int l, int r, int x)
{
  if (x == 0) {
    return 0;
  }

  if (l > r || x < 0) {
    return -1;
  }

  int leftReduce = minOperations(nums, l + 1, r, x - nums[l]);
  int rightReduce = minOperations(nums, l, r - 1, x - nums[r]);

  if (leftReduce == -1 && rightReduce == -1) {
    return -1;
  }

  if (leftReduce == -1) {
    return rightReduce + 1;
  }

  if (rightReduce == -1) {
    return leftReduce + 1;
  }

  return min(leftReduce, rightReduce) + 1;
}

// ! 1.
int minOperationsDP(vector<int>& nums, int x)
{
  int n = nums.size();

  return minOperations(nums, 0, n - 1, x);
}

int minOperations(vector<int>& nums, int x)
{
  int n = nums.size();

  int l = 0,
      r = 0,
      sum = nums[l];

  int ans = INT_MAX;

  int arrSum = 0;
  for (int num: nums) {
    arrSum += num;
  }

  int requiredWindowSum = arrSum - x;

  if (requiredWindowSum < 0) {
    return -1;
  }

  if (requiredWindowSum == 0) {
    return n;
  }

  while (l < n && r < n) {
    if (sum == requiredWindowSum) {
      int subArrayLen = r - l + 1;
      int restLen = n - subArrayLen;

      ans = min(ans, restLen);

      sum -= nums[l];
      l++;
    } else if (sum < requiredWindowSum && r + 1 < n) {
      r++;
      sum += nums[r];
    } else {
      sum -= nums[l];
      l++;
    }
  }

  return ans == INT_MAX ? -1 : ans;
}

void solution()
{
  int n, x;
  cin >> n >> x;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << minOperations(nums, x) << endl;
}

int main()
{
  solution();

  return 0;
}
