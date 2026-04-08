#include <bits/stdc++.h>

using namespace std;

int longestOnes(vector<int>& nums, int k)
{
  int n = nums.size();

  int l = 0;
  int oneCount = 0,
      zeroCount = 0;

  int ans = 0;

  for (int r = 0; r < n; r++) {
    if (nums[r] == 1) {
      oneCount++;
    }

    if (nums[r] == 0) {
      zeroCount++;
    }

    while (zeroCount > k) {
      if (nums[l] == 1) {
        oneCount--;
      } else if (nums[l] == 0) {
        zeroCount--;
      }

      l++;
    }

    ans = max(oneCount + zeroCount, ans);
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

  cout << longestOnes(nums, k) << endl;
}

int main()
{
  solution();

  return 0;
}
