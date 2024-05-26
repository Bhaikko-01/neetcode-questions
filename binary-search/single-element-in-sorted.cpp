#include <bits/stdc++.h>

using namespace std;

/**
 * Take care of extreme conditions where
 *  mid + 1 <= r and mid - 1 >= l
 * mid is even
 *  currEl is first of repeated -> unique is on right
 *    r = mid - 1
 *  currEl is second of repeated -> unique is on left
 *    l = mid + 1
 * mid is odd
 *  currEl is second of repeated -> unique is on right
 *    r = mid - 2
 *  currEL is first of repeated -> unique is on left
 *    l = mid + 1
*/

int singleNonDuplicate(vector<int>& nums)
{
  int n = nums.size();

  int l = 0,
      r = n - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    bool leftMatch = false;
    bool rightMatch = false;

    if (mid - 1 >= l) {
      leftMatch = nums[mid] == nums[mid - 1];
    }

    if (mid + 1 <= r) {
      rightMatch = nums[mid] == nums[mid + 1];
    }

    if (!leftMatch && !rightMatch) {
      return nums[mid];
    }

    if (mid & 1) {
      // Odd
      if (leftMatch) {
        l = mid + 1;
      } else if (rightMatch) {
        r = mid - 1;
      }
    } else {
      // Even
      if (leftMatch) {
        r = mid - 2;
      } else if (rightMatch) {
        l = mid + 2;
      }
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

  cout << singleNonDuplicate(nums) << endl;
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
