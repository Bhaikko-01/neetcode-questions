/**
 * 1. Binary Search - O(2logn)
 *      Normal binary search method will be used.
 *        If searching for leftBoundary
 *          If target is found
 *            Reduce array for leftSearch since we need leftBoundary
 *          Else normal decision based on target
 *        If searching for rightBoundary,
 *          If target is found
 *            Reduce array to right
 *          Else normal decision based on target
 *        Always record the index when target is found at mid as that index will be returned
 *          once we are done with searching
 */

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& nums, int l, int r, int target, bool isLeftSearch)
{
  int index = -1;
  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      index = mid;

      if (isLeftSearch) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } else if (target > nums[mid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return index;
}

vector<int> searchRange(vector<int>& nums, int target)
{
  int n = nums.size();

  int leftBoundary = binarySearch(nums, 0, n - 1, target, true);
  int rightBoundary = binarySearch(nums, 0, n - 1, target, false);

  return { leftBoundary, rightBoundary };
}

void solution()
{
  int n, target;
  cin >> n >> target;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> boundaries = searchRange(nums, target);
  cout << boundaries[0] << " " << boundaries[1] << endl;
}

int main()
{
  solution();

  return 0;
}
