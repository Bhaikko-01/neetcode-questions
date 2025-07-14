/**
 * 1. DP - O(n^2)
 *      Perform DP to get minimum value with possibliities of index and k
 * 2. Brute Force - O(n^2)
 *      For every capability possible from nums, being its value
 *        try satisfying the condition of robbing houses with k
 *        If condition is satisfied, the minimum of them is answer
 *      Condition satisfying code can be done in both DP and Greedy with both as O(n)
 * 3. Binary Search
 *      Run binary search on possible capabilities after sorting it
 *        Need to copy array and sort it since houses configuration cannot be changed
 *      Condition satisfying remains same
 *      If condition met, go left
 *      Else go right
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * It is ok if this is solved using DP
 * Greedy for this works too as we only need to tell if its is possible or not
 *   In this, we are picking element from left so we can skip the right one and continue
 *    checking if we have possible houses
 */
bool robHouse(vector<int>& nums, int k, int maxHouse)
{
  int n = nums.size();

  int count = 0;

  for (int i = 0; i < n; i++) {
    if (nums[i] <= maxHouse) {
      count++;
      i++;
    }

    if (count >= k) {
      return true;
    }
  }

  return count >= k;
}

int minCapabilityBrute(vector<int>& nums, int k)
{
  int n = nums.size();

  vector<int> sortedCopy(nums);
  sort(sortedCopy.begin(), sortedCopy.end());

  for (int currCapabilityIndex = 0; currCapabilityIndex < n; currCapabilityIndex++) {
    int currCapability = sortedCopy[currCapabilityIndex];

    bool numHousesPossible = robHouse(nums, k, currCapability);

    if (numHousesPossible) {
      return currCapability;
    }
  }

  return 0;
}

int minCapability(vector<int>& nums, int k)
{
  int n = nums.size();

  int ans = INT_MAX;

  vector<int> sortedCopy(nums);
  sort(sortedCopy.begin(), sortedCopy.end());

  int l = 0,
      r = n - 1;

  while (l <= r) {
    int currCapabilityIndex = (l + r) / 2;
    int currCapability = sortedCopy[currCapabilityIndex];

    bool numHousesPossible = robHouse(nums, k, currCapability);

    if (numHousesPossible) {
      ans = min(ans, currCapability);

      r = currCapabilityIndex - 1;
    } else {
      l = currCapabilityIndex + 1;
    }
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

  cout << minCapabilityBrute(nums, k) << endl;
  cout << minCapability(nums, k) << endl;
}

int main()
{
  solution();

  return 0;
}
