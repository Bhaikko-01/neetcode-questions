#include <bits/stdc++.h>

using namespace std;

int countGlobalInversions(vector<int>& nums, int l, int mid, int r)
{
  int i = l,
      j = mid + 1;

  int inversions = 0;

  vector<int> mergedArray;

  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {
      mergedArray.push_back(nums[i]);
      i++;
    } else {
      // Inversions for current element in right array will be
      // current element in left + all elements to its right as
      // element in right array will be discarded and never be compared again
      inversions += (mid - i + 1);
      mergedArray.push_back(nums[j]);
      j++;
    }
  }

  while (i <= mid) {
    mergedArray.push_back(nums[i]);
    i++;
  }

  while (j <= r) {
    mergedArray.push_back(nums[j]);
    j++;
  }

  for (int i = l, j = 0; i <= r; i++, j++) {
    nums[i] = mergedArray[j];
  }

  return inversions;
}

int globalInversions(vector<int>& nums, int l, int r)
{
  int arrLen = r - l + 1;

  if (arrLen <= 1) {
    return 0;
  }

  int mid = (l + r) / 2;

  int leftInversions = globalInversions(nums, l, mid);
  int rightInversions = globalInversions(nums, mid + 1, r);

  int currInversions = countGlobalInversions(nums, l, mid, r);

  return leftInversions + rightInversions + currInversions;
}

int globalInversions(vector<int> nums)
{
  int n = nums.size();

  return globalInversions(nums, 0, n - 1);
}

int localInversions(vector<int>& nums)
{
  int n = nums.size();
  int count = 0;

  for (int i = 0; i < n - 1; i++) {
    if (nums[i] > nums[i + 1]) {
      count++;
    }
  }

  return count;
}

bool isIdealPermutation(vector<int>& nums)
{
  int local = localInversions(nums);
  int global = globalInversions(nums);

  return local == global;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << isIdealPermutation(nums) << endl;
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
