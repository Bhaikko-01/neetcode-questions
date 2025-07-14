/**
 * 1. Sliding Window - O(n)
 *      Maintain window with all elements frequency in it in HashMap
 *        It is assumed that window elements will have frequency less than k
 *      Only 'r' element frequency is matched due to assumption above
 *      If 'r' element frequency exceed, remove 'l' till 'r' frequency is stable
 *        as 'r' element will make window invalid till it is compensated.
 *      Since we need 'subarrays', 'l' can be removed till window is valid
*/

#include <bits/stdc++.h>

using namespace std;

int maxSubarrayLength(vector<int>& nums, int k)
{
  int n = nums.size();

  int l = 0,
      r = 0;

  int ans = 0;

  unordered_map<int, int> windowFreq;

  while (r < n) {
    windowFreq[nums[r]]++;

    while (true) {
      if (windowFreq[nums[r]] > k) {
        windowFreq[nums[l]]--;
        l++;
      } else {
        break;
      }
    }

    ans = max(ans, r - l + 1);

    r++;
  }

  return ans;
}

void solution()
{
  int n, goal;
  cin >> n >> goal;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxSubarrayLength(nums, goal) << endl;
}

int main()
{
  solution();

  return 0;
}
