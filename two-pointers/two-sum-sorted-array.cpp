/**
 * 1. Two pointer approach - O(n) [T]
 *  Get sum of left and right point.
 *    If this sum matches target, this is ans
 *    If sum > target, r-- because we need to decrease sum to get closer to target
 *    else sum < target, l++ because we need to increase sum to get closer to target
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
  int n = numbers.size();
  int l = 0,
      r = n - 1;

  vector<int> ans(2, -1);

  while (l < r) {
    int currSum = numbers[l] + numbers[r];

    if (currSum == target) {
      ans[0] = l + 1;
      ans[1] = r + 1;
      return ans;
    } else if (currSum < target) {
      l++;
    } else if (currSum > target) {
      r--;
    }
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

  vector<int> ans = twoSum(nums, k);
  cout << ans[0] << " " << ans[1] << endl;
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
