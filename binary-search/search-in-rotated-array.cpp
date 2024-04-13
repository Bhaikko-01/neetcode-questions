/**
 * 1. Binary Search - O(logn)
 *    Check mid element as target
 *      If not found there, decision is taken based on
 *        left sorted or right sorted part AND
 *        element is in this subarray
 *    isLeftSorted can be found by comparsing arr[l] and arr[mid]
 *      if isLeftSorted -> check if target in bound of l and mid
 *        if nums[l] <= target < nums[mid] -> r = mid - 1
 *        else l = mid + 1
 *      else isRightSorted
 *        if nums[mid] < target <= nums[r] -> l = mid + 1
 *        else r = mid - 1
*/

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target)
{
  int n = nums.size();
  int l = 0, r = n - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      return mid;
    } else {
      bool isLeftSorted = nums[l] <= nums[mid];

      if (isLeftSorted) {
        if (nums[l] <= target && target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[r]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
  }

  return -1;
}

void solution()
{
  int n, target;
  cin >> n >> target;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << search(nums, target) << endl;
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
