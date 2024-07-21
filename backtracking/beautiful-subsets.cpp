#include <bits/stdc++.h>

using namespace std;

bool checkAbsoluteDiff(vector<int>& arr, int k)
{
  int n = arr.size();

  unordered_map<int, bool> occurence;

  for (int i = 0; i < n; i++) {
    int rem1 = arr[i] - k;
    int rem2 = arr[i] + k;

    if (occurence[rem1] || occurence[rem2]) {
      return true;
    }

    occurence[arr[i]] = true;
  }

  return false;
}

int beautifulSubsets(vector<int>& nums, int currIndex, int k, vector<int>& subset)
{
  int n = nums.size();

  if (currIndex == n) {
    return 0;
  }

  int excluded = beautifulSubsets(nums, currIndex + 1, k, subset);

  int included = 0;
  subset.push_back(nums[currIndex]);

  bool subsetPossible = !checkAbsoluteDiff(subset, k);

  if (subsetPossible) {
    included = beautifulSubsets(nums, currIndex + 1, k, subset) + 1;
  }

  subset.pop_back();

  return excluded + included;
}

int beautifulSubsets(vector<int>& nums, int k)
{
  vector<int> currSubset;

  return beautifulSubsets(nums, 0, k, currSubset);
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << beautifulSubsets(nums, k) << endl;
}

int main()
{
  solution();

  return 0;
}
