#include <bits/stdc++.h>

using namespace std;

void mergeSortedArrays(vector<int>& nums, int l, int mid, int r)
{
  int i = l,
      j = mid + 1;

  vector<int> mergedArray;

  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {
      mergedArray.push_back(nums[i]);
      i++;
    } else {
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
}

void mergeSort(vector<int>& nums, int l, int r)
{
  if (l >= r) {
    return;
  }

  int mid = (l + r) / 2;
  mergeSort(nums, l, mid);
  mergeSort(nums, mid + 1, r);

  mergeSortedArrays(nums, l, mid, r);
}

void mergeSort(vector<int>& nums)
{
  int n = nums.size();
  mergeSort(nums, 0, n - 1);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  mergeSort(nums);

  for (int x: nums) {
    cout << x << " ";
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
