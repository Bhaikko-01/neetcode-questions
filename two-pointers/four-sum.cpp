#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> twoSum(vector<int>& nums, ll target, int l)
{
  int n = nums.size();

  int r = n - 1;

  vector<vector<int>> twoPairs;

  while (l < r) {
    ll sum = (ll)nums[l] + (ll)nums[r];

    if (sum == target) {
      twoPairs.push_back({ nums[l], nums[r] });
    }

    if (sum > target) {
      r--;
    } else {
      l++;
    }
  }

  return twoPairs;
}

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
  int n = nums.size();

  sort(nums.begin(), nums.end());

  vector<vector<int>> ans;
  set<vector<int>> uniqueAns;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll newTarget = (ll)target - ((ll)nums[i] + (ll)nums[j]);

      vector<vector<int>> twoSumPairs = twoSum(nums, newTarget, j + 1);

      for (vector<int> twoSumPair: twoSumPairs) {
        uniqueAns.insert({ nums[i], nums[j], twoSumPair[0], twoSumPair[1] });
      }
    }
  }

  for (set<vector<int>>::iterator i = uniqueAns.begin(); i != uniqueAns.end(); i++) {
    ans.push_back(*i);
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

  vector<vector<int>> ans = fourSum(nums, target);

  for (auto x: ans) {
    for (int y: x) {
      cout << y << " ";
    }
    cout << endl;
  }
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
