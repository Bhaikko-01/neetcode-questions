/**
 * 1. Brute Force - O(n^2)
 *      Consider every subset and find ans
 *      Return one with max ans possible
 * 2. Stack and Prefix sum - O(n)
 *      Get leftMin and rightMin for all elements
 *      Consider if each val was min of subarray
 *        Use leftMin and rightMin to determine indexes to expand till specific index
 *        Use indexes and prefixSum to get currPossible ans
 */

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

vector<ll> getPrefixSum(vector<int>& nums)
{
  int n = nums.size();

  vector<ll> prefixSums(n, 0);
  prefixSums[0] = nums[0];

  for (int i = 1; i < n; i++) {
    prefixSums[i] += prefixSums[i - 1] + (ll)nums[i];
  }

  return prefixSums;
}

vector<int> getLeftMin(vector<int>& nums)
{
  int n = nums.size();

  stack<int> leftMinStack;
  vector<int> leftMin(n, -1);

  for (int i = 0; i < n; i++) {
    if (!leftMinStack.empty() && nums[leftMinStack.top()] < nums[i]) {
      leftMin[i] = leftMinStack.top();
    } else {
      while (!leftMinStack.empty() && nums[leftMinStack.top()] >= nums[i]) {
        leftMinStack.pop();
      }

      leftMin[i] = leftMinStack.empty() ? -1 : leftMinStack.top();
    }

    leftMinStack.push(i);
  }

  return leftMin;
}

vector<int> getRightMin(vector<int>& nums)
{
  int n = nums.size();

  stack<int> rightMinStack;
  vector<int> rightMin(n, -1);

  for (int i = n - 1; i >= 0; i--) {
    if (!rightMinStack.empty() && nums[rightMinStack.top()] < nums[i]) {
      rightMin[i] = rightMinStack.top();
    } else {
      while (!rightMinStack.empty() && nums[rightMinStack.top()] >= nums[i]) {
        rightMinStack.pop();
      }

      rightMin[i] = rightMinStack.empty() ? -1 : rightMinStack.top();
    }

    rightMinStack.push(i);
  }

  return rightMin;
}

int maxSumMinProduct(vector<int>& nums)
{
  int n = nums.size();

  vector<ll> prefixSum = getPrefixSum(nums);
  vector<int> leftMin = getLeftMin(nums);
  vector<int> rightMin = getRightMin(nums);

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    ll curr = rightMin[i] == -1 ? prefixSum[n - 1] : prefixSum[rightMin[i] - 1];

    if (leftMin[i] != -1) {
      curr -= prefixSum[leftMin[i]];
    }

    ans = max(ans, curr * nums[i]);
  }

  return ans % MOD;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxSumMinProduct(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
