/**
 * 1. Binary Search with Part Linear search - O(n)
 *      Pretty much same as search-in-rotated-array1
 *      Check mid if same as target,
 *      if not same then
 *        check if left sub-array is sorted and target is in that subarray then search there
 *        else search in right sub-array
 *        check if right sub-array is sorted and target is in that subarray then search there
 *        else search in left sub-array
 *      The above will fail if extreme elements are equal as we do not know which sub-array to check
 *        then we can simply do linear search in both sub-array
 * 2. Binary search with fallback - O(logn)
 *      If stalemate occurs for arr[l] == arr[mid] == arr[r] then
 *        l++ and r-- then continue the search
 */

#include <bits/stdc++.h>

using namespace std;

bool search(vector<int>& nums, int target)
{
  int n = nums.size();

  int l = 0, r = n - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      return true;
    } else {

      if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
        l++;
        r--;
      } else {
        bool isLeftSorted = nums[l] <= nums[mid];

        if (isLeftSorted) {
          if (nums[l] <= target && target <= nums[mid]) {
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        } else {
          if (nums[mid] <= target && target <= nums[r]) {
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
      }
    }
  }

  return false;
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
  solution();

  return 0;
}
