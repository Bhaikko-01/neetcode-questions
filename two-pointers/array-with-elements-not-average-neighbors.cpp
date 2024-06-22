/**
 * 1. Two pointer with Sorting - O(nlogn)
 *      If we can ensure that an element is surrounded by either both greater or less than current el,
 *        then average value can never be same as current
 *      To do this, fill alternative position of array by first and second half of array
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums)
{
  int n = nums.size();

  sort(nums.begin(), nums.end());

  vector<int> ans(n);

  int lowerIndex = 0, higherIndex = ((n + 1) / 2);

  for (int i = 0; i < n; i += 2) {
    ans[i] = nums[lowerIndex++];

    if (i + 1 < n) {
      ans[i + 1] = nums[higherIndex++];
    }
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

  vector<int> ans = rearrangeArray(nums);

  for (int num: ans) {
    cout << num << " ";
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
