#include <bits/stdc++.h>

using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot)
{
  int n = nums.size();

  int elLess = 0,
      elEqual = 0;

  vector<int> ans(n, -1);

  for (int i = 0; i < n; i++) {
    if (nums[i] < pivot) {
      elLess++;
    } else if (nums[i] == pivot) {
      elEqual++;
    }
  }

  int equalIndex = elLess;
  int lessIndex = 0;
  int greatIndex = equalIndex + elEqual;

  for (int i = 0; i < n; i++) {
    if (nums[i] < pivot) {
      ans[lessIndex++] = nums[i];
    } else if (nums[i] == pivot) {
      ans[equalIndex++] = nums[i];
    } else {
      ans[greatIndex++] = nums[i];
    }
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int pivot;
  cin >> pivot;

  vector<int> ans = pivotArray(nums, pivot);

  for (int num: ans) {
    cout << num << " ";
  }

  cout << endl;
}

int main()
{
  solution();

  return 0;
}
