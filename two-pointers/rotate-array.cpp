#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k)
{
  int n = nums.size();

  int effectiveRotation = k % n;

  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + effectiveRotation); // Rerversing first k element
  reverse(nums.begin() + effectiveRotation, nums.end()); // Reversing last n - k elements
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  rotate(nums, k);

  for (int num: nums) {
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
