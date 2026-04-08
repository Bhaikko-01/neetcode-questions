#include <bits/stdc++.h>

using namespace std;

using pp = pair<int, int>;

bool find132pattern(vector<int>& nums)
{
  int n = nums.size();

  stack<pp> pending;

  int minValue = nums[0];

  for (int num: nums) {
    while (!pending.empty() && pending.top().first <= num) {
      pending.pop();
    }

    if (!pending.empty () && num > pending.top().second) {
      return true;
    }

    pending.push({num, minValue});
    minValue = min(minValue, num);
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

  cout << find132pattern(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
