/**
 * 1. Brute Force - O(n^2)
 *      Rotate array when duplicate encountered
 * 2. Swap - O(n)
 *      Compare consecutive elements and find element greater than current
 *      swap and increment r
*/

#include <bits/stdc++.h>

using namespace std;

int removeDuplicatesBrute(vector<int>& nums)
{
  int n = nums.size();

  int i = 0,
      j = n - 1;

  for (int x = 1; x <= j;) {
    if (nums[x - 1] == nums[x]) {
      for (int w = x; w <= j - 1; w++) {
        swap(nums[w], nums[w + 1]);
      }

      j--;
    } else {
      x++;
    }
  }

  return j + 1;
}

int removeDuplicates(vector<int>& nums)
{
  int n = nums.size();

  int l = 0,
      r = 0;

  while (l + 1 < n && r < n) {
    if (nums[l] >= nums[l + 1]) {
      while (r < n && nums[r] <= nums[l]) {
        r++;
      }

      if (r == n) {
        break;
      }

      swap(nums[l + 1], nums[r]);
      r++;
    }

    l++;

    if (r < l) {
      r = l;
    }
  }

  return l + 1;
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
