/**
 * 1. Prefix Sum and Hashing - O(n)
 *      Maintain prefixSum and its remainder and index in hashMap
 *      If for current prefixSum, we have three possiblities
 *        - remainder is zero -> check if prefixSum is of more than 2 length then ans is true
 *          since subarray from starting can have sum divisible by k
 *        - remainder has occured previously -> this means, sum between prev Remainder occurence
 *          and currIndex made full cycle to give same remainder, hence sum is divisible by k
 *        - remainder has not occured previously -> simply add it to remainderIndexOccurence
 *      If ans not found till end, then not possible
*/

#include <bits/stdc++.h>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k)
{
  int n = nums.size();
  
  unordered_map<int, int> remainderOccurence;
  int prefixSum = 0;

  for (int i = 0; i < n; i++) {
    prefixSum += nums[i];
    int currRem = prefixSum % k;

    if (i >= 2 && currRem == 0) {
      return true;
    }

    if (remainderOccurence.find(currRem) != remainderOccurence.end()) {
      if (i - remainderOccurence[currRem] > 1) {
        return true;
      }
    } else {
      remainderOccurence[currRem] = i;
    }
  }

  return false;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << checkSubarraySum(nums, k) << endl;
}

int main()
{
  solution();

  return 0;
}
 