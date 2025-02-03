#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll maxAlternatingSum(vector<int>& nums, int index, bool isEvenIndex, vector<vector<ll>>& dp)
{
  int n = nums.size();

  if (index >= n) {
    return 0;
  }

  if (dp[index][isEvenIndex] != -1) {
    return dp[index][isEvenIndex];
  }

  ll excludeCurr = maxAlternatingSum(nums, index + 1, isEvenIndex, dp);
  ll includeCurr = maxAlternatingSum(nums, index + 1, !isEvenIndex, dp);

  if (isEvenIndex) {
    includeCurr += nums[index];
  } else {
    includeCurr -= nums[index];
  }

  dp[index][isEvenIndex] = max(includeCurr, excludeCurr);

  return dp[index][isEvenIndex];
}

long long maxAlternatingSum(vector<int>& nums)
{
  int n = nums.size();
  vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));

  return maxAlternatingSum(nums, 0, true, dp);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxAlternatingSum(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
