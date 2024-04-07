#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
  int n = nums.size();
  unordered_map<int, int> remainingValueMapping;

  vector<int> ans(2);

  for (int i = 0; i < n; i++) {
    int currVal = nums[i];
    int remainingVal = target - nums[i];

    if (remainingValueMapping.find(remainingVal) != remainingValueMapping.end()) {
      ans[0] = i;
      ans[1] = remainingValueMapping[remainingVal];

      break;
    }

    remainingValueMapping[currVal] = i;
  }

  return ans;
}

void solution()
{
  int n, target;
  cin >> n >> target;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> ans = twoSum(nums, target);
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
