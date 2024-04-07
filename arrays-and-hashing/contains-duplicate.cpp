#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums)
{
  int n = nums.size();

  unordered_map<int, bool> occurence;

  for (int i = 0; i < n; i++) {
    if (occurence.find(nums[i]) != occurence.end()) {
      return true;
    }

    occurence[nums[i]] = true;
  }

  return false;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << containsDuplicate(nums) << endl;
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
