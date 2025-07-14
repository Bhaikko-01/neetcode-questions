/**
 * 1. Brute Force - O(n^2)
 *      For every element, move to right and check max width possible
 *      Max right we can go till curr element is greater than all on right
 *        This is optimised by maintaining rightMaxes
 * 2. Sliding Window - O(n)
 *      Maintain array of rightMaxes for every element to right
 *        containing rightMax element possible for curr. Created by processing from right
 *      Maximize window using rightMaxes
 *        if left has no rightMax then no point continuing with that window
 *          we decrease window with l++
 *        else
 *          check if width is better than current answer
 *          increase window with r++
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> getRightMaxes(vector<int>& nums)
{
  int n = nums.size();

  vector<int> rightMaxes(n);
  int currMax = INT_MIN;

  for (int i = n - 1; i >= 0; i--) {
    currMax = max(currMax, nums[i]);
    rightMaxes[i] = currMax;
  }

  return rightMaxes;
}

int maxWidthRamp(vector<int>& nums)
{
  int n = nums.size();

  vector<int> rightMaxes = getRightMaxes(nums);

  int ans = 0;

  int l = 0,
      r = 0;

  while (r < n) {
    while (l <= r && nums[l] > rightMaxes[r]) {
      l++;
    }

    int currRamp = r - l;
    ans = max(ans, currRamp);

    r++;
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxWidthRamp(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
