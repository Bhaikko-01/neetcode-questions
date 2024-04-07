/**
 * 1. Break the problem into two sum - O(n^2) + O(n^3 * (3log3 + logn)) - [T]
 *  pick element from beginning and run twoSum(a[j], a[n - 1], target - arr[i])
 *  Push the triplets into set after sorting triplets. Set will compare vector<int> lexographically
 * 2. Sort the array, use two pointer - O(nlogn) + O(n^2 * logn) - [T]
 *  Sort the array, run twoSum with two pointer approach, twoSum(a[j], a[n - 1], target - arr[i])
 *  Push the found triplet directly into set. No need to sort as whole array was sorted
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

// ! 1.
vector<pp> twoSum(vector<int>& nums, int target)
{
  int n = nums.size();
  unordered_map<int, int> remainingValueMapping;

  vector<pp> ans;

  for (int currVal: nums) {
    int remainingVal = target - currVal;

    pp currAnsPair;

    if (remainingValueMapping.find(remainingVal) != remainingValueMapping.end()) {
      currAnsPair.first = currVal;
      currAnsPair.second = remainingValueMapping[remainingVal];

      ans.push_back(currAnsPair);
    }

    remainingValueMapping[currVal] = currVal;
  }

  return ans;
}

// ! 1.
vector<vector<int>> threeSum(vector<int>& nums, int target)
{
  int n = nums.size();

  vector<vector<int>> ans;

  for (int i = 0; i < nums.size(); i++) {
    int firstNum = nums[i];
    int newTarget = target - firstNum;

    vector<int> remainingArray(nums.begin() + i + 1, nums.end());

    vector<pp> twoSumAns = twoSum(remainingArray, newTarget);

    for (pp twoSumPair: twoSumAns) {
      vector<int> triplet;

      triplet.push_back(firstNum);
      triplet.push_back(twoSumPair.first);
      triplet.push_back(twoSumPair.second);

      ans.push_back(triplet);
    }
  }

  // Two vectors are compared lexographically
  // hence vector<int> can be inserted
  set<vector<int>> uniqueTriplets;
  for (vector<int> triplet: ans) {
    sort(triplet.begin(), triplet.end());

    uniqueTriplets.insert(triplet);
  }

  vector<vector<int>> uniqueAns;

  for (set<vector<int>>::iterator it = uniqueTriplets.begin(); it != uniqueTriplets.end(); it++) {
    uniqueAns.push_back(*it);
  }

  return uniqueAns;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<vector<int>> ans = threeSum(nums, 0);

  for (vector<int> triplet: ans) {
    cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
  }
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
