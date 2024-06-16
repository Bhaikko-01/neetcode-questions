#include <bits/stdc++.h>

using namespace std;

int maxSubarraySumCircular(vector<int>& nums)
{
  int n = nums.size();

  int currMaxSum = 0,
      maxSum = INT_MIN,
      currMinSum = 0,
      minSum = INT_MAX,
      total = 0;

  for (int i = 0; i < n; i++) {
    total += nums[i];
    currMaxSum += nums[i];
    currMinSum += nums[i];

    maxSum = max(maxSum, currMaxSum);
    minSum = min(minSum, currMinSum);

    if (currMaxSum < 0) {
      currMaxSum = 0;
    }

    if (currMinSum > 0) {
      currMinSum = 0;
    }
  }

  if (maxSum < 0) {
    return maxSum;
  }

  return max(maxSum, total - minSum);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxSubarraySumCircular(nums) << endl;
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
