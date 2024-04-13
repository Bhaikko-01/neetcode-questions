/**
 * 1. Searching algo - O(logn)
 *      search till l <= r
 *      if element found at mid, return
 *      else
 *        if target is greater than mid, search in right part
 *        else search in left part
*/

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target)
{
  int n = nums.size();

  int l = 0,
      r = n - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      return mid;
    } else if (target > nums[mid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  // cout << r << endl;

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
