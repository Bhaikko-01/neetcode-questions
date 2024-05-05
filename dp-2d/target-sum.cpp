/**
 * 1. Decision Tree
 *      Maintain currIndex and currVal in further recursion calls
 *      If currIndex == n && currVal == target
 *          found a way, return 1
 *      Else
 *          return 0
 *      Call recursion calls by considering nums[currIndex] as positive and negative
 *      return considerAsPositive + considerAsNegative
 *    Memoize on currIndex and currVal
*/

#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

int findTargetSumWays(vector<int>& nums, int target, int currIndex, int currVal, unordered_map<string, int>& occured)
{
  int n = nums.size();
  string key = getKey(currIndex, currVal);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (currIndex == n) {
    return currVal == target;
  }

  if (currIndex > n) {
    return 0;
  }

  int considerCurrAsPositive = findTargetSumWays(nums, target, currIndex + 1, currVal + nums[currIndex], occured);
  int considerCurrAsNegative = findTargetSumWays(nums, target, currIndex + 1, currVal - nums[currIndex], occured);

  occured[key] = considerCurrAsPositive + considerCurrAsNegative;

  return occured[key];
}

int findTargetSumWays(vector<int>& nums, int target)
{
  unordered_map<string, int> occured;

  return findTargetSumWays(nums, target, 0, 0, occured);
}

void solution()
{
  int n, target;
  cin >> n >> target;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << findTargetSumWays(nums, target) << endl;
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
