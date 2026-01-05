/**
 * 1. Brute Force - O(n)
 *    Search linearly
 * 2. Binary search O(logn)
 *    If array between l and r is sorted, minEl = min(minEl, arr[l])
 *    Else take decision based on left and right subarrays based on in which sorted portion we are
 *      At each mid, check if this is minElement as well, minEl = min(minEl, arr[mid])
 *      if (arr[l] <= arr[mid]) // In left sorted portion, move to right
 *        l = mid + 1
 *      else // In right sorted portion, move to left
 *        r = mid - 1
 *    Note - We track minEl as we might skip the minimum element
 *      when doing l = mid + 1 or r = mid - 1
*/

#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums)
{
  int n = nums.size();
  int l = 0, r = n - 1;

  int minEl = nums[l];

  while (l <= r) {
    if (nums[l] < nums[r]) {
      minEl = min(minEl, nums[l]);
      break;
    } else {
      int mid = (l + r) / 2;

      minEl = min(minEl, nums[mid]);
      if (nums[l] <= nums[mid]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }

  return minEl;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << findMin(nums) << endl;
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

// 2 3 4 5 6 1
// l = 0, r = 6
// minIndex 6
// mid = 5

// 6 1 2 3 4 5
