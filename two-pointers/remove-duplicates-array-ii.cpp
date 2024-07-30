/**
 * 1. Two pointer - O(n) [T]
 *      If nums[i - 1] == nums[i] then increase count
 *      else count = 1
 *      Moving elements to left till currCount <= 2
*/

#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
  int n = nums.size();

  int l = 1,
      count = 1;

  for (int i = 1; i < n; i++) {
    if (nums[i - 1] == nums[i]) {
      count++;
    } else {
      count = 1;
    }

    if (count <= 2) {
      nums[l++] = nums[i];
    }
  }

  return l;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int k = removeDuplicates(nums);

  for (int i = 0; i < k; i++) {
    cout << nums[i] << " ";
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
