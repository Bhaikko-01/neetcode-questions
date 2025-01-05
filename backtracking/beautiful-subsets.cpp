/**
 * 1. Brute Force - O(2^n)
 *      Take decision of adding or not for curr element which would create a decision tree
 *      Check absolute difference condition on currNum only if its counterpart exists in subset or not
 *        Maintain subset hashmap rather than array so lookup can be done in O(1)
 *        check1 = currNum - k; check2 = currNum + k;
 *      To save memory, use hashmap by reference in function calls,
 *        maintain frequencies in hashmap and decrease it once done with that call
 */

#include <bits/stdc++.h>

using namespace std;

bool checkAbsoluteDiff(unordered_map<int, int>& subset, int k, int currNum)
{
  int check1 = currNum + k;
  int check2 = currNum - k;

  return (
    subset[check1] == 0 &&
    subset[check2] == 0
  );
}

int beautifulSubsets(vector<int>& nums, int currIndex, int k, unordered_map<int, int>& subset)
{
  int n = nums.size();

  if (currIndex == n) {
    return 0;
  }

  int excluded = beautifulSubsets(nums, currIndex + 1, k, subset);

  int included = 0;
  subset[nums[currIndex]]++;

  bool subsetPossible = checkAbsoluteDiff(subset, k, nums[currIndex]);

  if (subsetPossible) {
    included = beautifulSubsets(nums, currIndex + 1, k, subset) + 1;
  }

  subset[nums[currIndex]]--;

  return excluded + included;
}

int beautifulSubsets(vector<int>& nums, int k)
{
  unordered_map<int, int> currSubset;

  return beautifulSubsets(nums, 0, k, currSubset);
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << beautifulSubsets(nums, k) << endl;
}

int main()
{
  solution();

  return 0;
}
