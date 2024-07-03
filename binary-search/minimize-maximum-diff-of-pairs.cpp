#include <bits/stdc++.h>

using namespace std;

int minimizeMax(vector<int>& nums, int p)
{
  int n = nums.size();

  sort(nums.begin(), nums.end());

  int l = 0, r = nums[n - 1] - nums[0];
  int minAns = INT_MAX;

  while (l <= r) {
    int mid = (l + r) / 2;
    int count = 0;

    for (int i = 0; i + 1 < n;) {
      if (abs(nums[i] - nums[i + 1]) <= mid) {
        count++;
        i += 2;
      } else {
        i++;
      }
    }

    if (count >= p) {
      minAns = min(minAns, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return minAns;
}

void solution()
{
  int n, p;
  cin >> n >> p;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << minimizeMax(nums, p) << endl;
}

int main()
{
  solution();

  return 0;
}
