#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
  priority_queue<int> maxHeap(nums.begin(), nums.end());

  for (int i = 1; i <= k - 1; i++) {
    maxHeap.pop();
  }

  return maxHeap.top();
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << findKthLargest(nums, k) << endl;
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
