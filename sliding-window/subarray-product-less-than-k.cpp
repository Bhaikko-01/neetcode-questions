/**
 * 1. Brute Force - O(n^2)
 *      Generate all subarrays and count which satisfy the condition
 * 2. Sliding Window - O(n)
 *      Maintain window that has product less than goal
 *      If window product is more than goal, decrease size of window
 *      Else increase window size
 *      For ans, length of window is added to final ans after processing right
 *        This is done as
 *          - All elements of array are positive, which means if multiplying that element is less than goal
 *            then all subarray possible with that element will also be smaller than goal
 *          - Adding this element will create lenOfWindow new subarrays as this will be the last element of all
 *            those subarrays
*/

#include <bits/stdc++.h>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int goal)
{
  int n = nums.size();

  if (goal == 0) {
    return 0;
  }

  int l = 0,
      r = 0,
      windowProd = 1;

  int ans = 0;

  while (r < n) {
    windowProd *= nums[r];

    while (l <= r) {
      if (windowProd >= goal) {
        windowProd /= nums[l];
        l++;
      } else {
        break;
      }
    }

    ans += (r - l + 1);
    r++;
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

  cout << numSubarrayProductLessThanK(nums, goal) << endl;
}

int main()
{
  solution();

  return 0;
}
