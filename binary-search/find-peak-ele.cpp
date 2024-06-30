/**
 * 1. Binary Search - O(logn)
 *      Check if mid element if greater than its neighbor.
 *      If yes, return that index
 *      Else, move towards greater element as eventually
 *        we either reach the end where it will be peak or find element which is greater than its neighbor
 */
#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int>& nums)
{
  int n = nums.size();

  int l = 0, r = n - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    bool greaterThanLeft = true;
    if (mid - 1 >= 0) {
      greaterThanLeft = nums[mid - 1] < nums[mid];
    }

    bool greaterThanRight = true;
    if (mid + 1 < n) {
      greaterThanRight = nums[mid + 1] < nums[mid];
    }

    if (greaterThanLeft && greaterThanRight) {
      return mid;
    }

    if (!greaterThanLeft) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << findPeakElement(nums) << endl;
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
