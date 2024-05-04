#include <bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums, int currIndex, unordered_map<int, int>& occured)
{
  int n = nums.size();

  if (occured.find(currIndex) != occured.end()) {
    return occured[currIndex];
  }

  if (currIndex >= n) {
    return 0;
  }

  // ! Taking decision whether to include current house and skip next house
  // ! OR skipping current house and taking next house
  int robCurrentHouse = rob(nums, currIndex + 2, occured) + nums[currIndex];
  int notRobCurrentHouse = rob(nums, currIndex + 1, occured);

  occured[currIndex] = max(robCurrentHouse, notRobCurrentHouse);

  return occured[currIndex];
}

int rob(vector<int>& nums)
{
  unordered_map<int, int> occured;

  return rob(nums, 0, occured);
}

int robDp(vector<int>& nums)
{
  int n = nums.size();

  vector<int> dp(n + 2, 0);
  dp[n - 1] = nums[n - 1];

  // ! i indicates the currIndex, index of smaller array of subproblems
  for (int i = n - 2; i >= 0; i--) {
    int robCurrentHouse = dp[i + 2] + nums[i];
    int notRobCurrentHouse = dp[i + 1];

    dp[i] = max(robCurrentHouse, notRobCurrentHouse);
  }

  return *max_element(dp.begin(), dp.end());
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << robDp(nums) << endl;
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
