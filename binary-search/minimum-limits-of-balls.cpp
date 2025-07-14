/**
 * 1. Brute Force - O(n^2)
 *      Try with each penalty for which, the elements can be broken
 *        Operation require to break a number to specified penalty is
 *          ceil(number / penalty) - 1
 *        Calculate total operations to convert all elements to specific penalty
 *      First penalty to fulfill is ans
 * 2. Binary Search - O(nlogn)
 *      Binary search can be used to search for penalty where
 *        l = 1, r = max(nums) since that is the max penalty possible if non broken
 *      Checking for penalty remains same as above
 */

#include <bits/stdc++.h>

using namespace std;

int minimumSizeBrute(vector<int>& nums, int maxOperations)
{
  int n = nums.size();

  int maxPenalty = *max_element(nums.begin(), nums.end());

  for (int penalty = 1; penalty <= maxPenalty; penalty++) {
    int operationsDone = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] > penalty) {
        operationsDone += ceil(nums[i] / (float)penalty) - 1;
      }

      if (operationsDone > maxOperations) {
        break;
      }
    }

    if (operationsDone <= maxOperations) {
      return penalty;
    }
  }

  return -1;
}

int minimumSize(vector<int>& nums, int maxOperations)
{
  int n = nums.size();

  int l = 1;
  int r = *max_element(nums.begin(), nums.end());
  int minPenalty = INT_MAX;

  while (l <= r) {
    int penalty = (l + r) / 2;

    long long operationsDone = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] > penalty) {
        operationsDone += ceil(nums[i] / (double)penalty) - 1;
      }

      if (operationsDone > maxOperations) {
        break;
      }
    }

    if (operationsDone <= maxOperations) {
      minPenalty = min(minPenalty, penalty);
      r = penalty - 1;
    } else {
      l = penalty + 1;
    }
  }

  return minPenalty;
}

void solution()
{
  int n, maxOperations;
  cin >> n >> maxOperations;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << minimumSizeBrute(nums, maxOperations) << endl;
  cout << minimumSize(nums, maxOperations) << endl;
}

int main()
{
  solution();

  return 0;
}
