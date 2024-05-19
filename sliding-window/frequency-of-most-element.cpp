/**
 * 1, Brute Force - O(n^2)
 *      Sort array
 *      For currEle, find elements before which satisfy current budget (k)
 *      ans = max(ans, count)
 * 2. Sliding Window - O(n)
 *      Sort array
 *      Maintain sum of window
 *      For currElement,
 *        numOfElToLeft = r - l;
 *        requiredBudget = numOfElToLeft * nums[r] - sum
 *      if requiredBudget for current Window is not satisfied
 *        move to left and decrease sum
 *      else
 *        move to right
 *        ans = max(ans, lenOfWindow)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int maxFrequencyBrute(vector<int>& nums, int k)
{
  int n = nums.size();

  int l = 0,
      r = 0;

  int ans = 0;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++) {
    int budget = k;
    int count = 1;

    for (int j = i - 1; j >= 0; j--) {
      int reqBudget = nums[i] - nums[j];

      if (reqBudget <= budget) {
        count++;
        budget -= reqBudget;
      } else {
        break;
      }
    }

    ans = max(ans, count);
  }

  return ans;
}

int maxFrequency(vector<int>& nums, int k)
{
  int n = nums.size();

  int l = 0,
      r = 0;

  int ans = 1;
  ll sum = 0;

  sort(nums.begin(), nums.end());

  while (r < n) {
    ll currEle = nums[r];

    while (true) {
      ll numEleBehind = r - l;
      ll budgetReqForCurrentWindow = numEleBehind * currEle - sum;

      if (budgetReqForCurrentWindow <= k) {
        break;
      }

      sum -= nums[l];
      l++;
    }

    ans = max(ans, r - l + 1);

    sum += currEle;
    r++;
  }

  return ans;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxFrequency(nums, k) << endl;
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
