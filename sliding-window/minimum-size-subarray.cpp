#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
  int n = nums.size();

  int minLen = INT_MAX;

  int l = 0, r = 0;
  int currSum = 0;

  while (r < n) {
    currSum += nums[r];

    while (l <= r && currSum >= target) {
      minLen = min(r - l + 1, minLen);

      currSum -= nums[l];
      l++;
    }

    r++;
  }

  return minLen == INT_MAX ? 0 : minLen;
}

void solution()
{
  int n, target;
  cin >> n >> target;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << minSubArrayLen(target, nums) << endl;
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
