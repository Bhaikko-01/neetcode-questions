#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums, int l, int mid, int r)
{
  vector<int> mergedArray;

  int i = l,
      j = mid + 1;

  while (i <= mid && j <= r) {
    if (nums[i] <= nums[j]) {
      mergedArray.push_back(nums[i++]);
    } else {
      mergedArray.push_back(nums[j++]);
    }
  }

  while (i <= mid) {
    mergedArray.push_back(nums[i++]);
  }

  while (j <= r) {
    mergedArray.push_back(nums[j++]);
  }

  int x = 0;
  for (int i = l; i <= r; i++) {
    nums[i] = mergedArray[x++];
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

  merge(nums, l, mid, r);
}

vector<int> sortArray(vector<int>& nums)
{
  int n = nums.size();

  mergeSort(nums, 0, n - 1);

  return nums;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> sortedNums = sortArray(nums);

  for (int x: sortedNums) {
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
