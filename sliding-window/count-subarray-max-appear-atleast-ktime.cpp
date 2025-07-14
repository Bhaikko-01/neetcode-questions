/**
 * 1. Sliding Window - O(n)
 *      Maintain window with maxEl frequency as k
 *      Treat that window as one element and add number of subarray formed by
 *        treating it as last element to get final answer
 *      Number of subarrays by el inserted at index x = x
 *      Hence, ans += (l + 1) where l is left of window
 *      If freq reaches more than k, reduce window
 *      If freq is equal to k, find l same as maxEl by reducing window,
 *        l will always be maxEl and r can be any number
 *        l and r window will always have freq equal to k
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long countSubarrays(vector<int>& nums, int k)
{
  int n = nums.size();

  int maxEl = *max_element(nums.begin(), nums.end());

  ll ans = 0;
  int count = 0;

  int l = 0,
      r = 0;

  while (r < n) {
    if (nums[r] == maxEl) {
      count++;
    }

    if (count == k + 1) {
      l++;
      count--;
    }

    if (count == k) {
      while (l <= r && nums[l] != maxEl) {
        l++;
      }

      ans += (l + 1);
    }

    r++;
  }

  return ans;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << countSubarrays(nums, k) << endl;
}

int main()
{
  solution();

  return 0;
}
