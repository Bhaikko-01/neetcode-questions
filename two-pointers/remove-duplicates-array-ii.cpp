/**
 * 1. Two pointer - O(n) [T]
 *      Maintain pointers l, r
 *      Maintain vals, currNum and count
 *      Consider following cases when comparing nums[l] and currNum
 *        if nums[l] == currNum
 *          Check count value and swap accordingly
 *          update currNum and count accordingly
 *          mark dupFound = true
 *        if nums[l] < currNum
 *          occured because of prev swap
 *          simply find el based of count and currNum
 *            if count == 2, need to find el strictly greater
 *              update currNum and count
 *            else find greater of equal
 *              if greater found, update currNum and count
 *        if nums[l] > currNum
 *          update currNum and count
 *      return l;
 *      Make sure when finding nextEl
 *        we never react r == n
*/

#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
  int n = nums.size();

  int l = 0,
      r = 0,
      currNum = nums[0],
      count = 0;

  while (r < n) {
    if (nums[l] == currNum) {
      if (count == 2) {
        while (r < n && nums[r] <= currNum) {
          r++;
        }

        if (r == n) {
          break;
        }

        swap(nums[l], nums[r]);

        currNum = nums[l];
        count = 1;
      } else {
        count++;
        r++;
      }

    } else if (nums[l] < currNum) {
      if (count < 2) {
        while (r < n && nums[r] < currNum) {
          r++;
        }

        if (r == n) {
          break;
        }

        swap(nums[l], nums[r]);

        if (nums[l] == currNum) {
          count++;
        } else {
          currNum = nums[l];
          count = 1;
        }
      } else {
        while (r < n && nums[r] <= currNum) {
          r++;
        }

        if (r == n) {
          break;
        }

        swap(nums[l], nums[r]);

        currNum = nums[l];
        count = 1;
      }
    } else if (nums[l] > currNum) {
      currNum = nums[l];
      count = 1;
      r++;
    }

    l++;

    if (r < l) {
      r = l;
    }
  }

  return l;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int k = removeDuplicates(nums);

  for (int i = 0; i < k; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
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
