/**
 * 1. Search for chain for each element - O(n^2)
 * 2. Sort array and find consecutive numbers - O(nlogn)
 * 3. Search for consecutive numbers - O(n) - [T + S]
 *  If element less than current exist, we have better answer
 *  Otherwise, keep searching for element greater than current
 *  Keep track of max for each chain
*/

#include <bits/stdc++.h>

using namespace std;

// ! 3.
int longestConsecutive(vector<int>& nums)
{
  int n = nums.size();

  unordered_map<int, bool> elementTraversed;

  for (int a: nums) {
    elementTraversed[a] = true;
  }

  int maxValue = 0;

  for (int currEle : nums) {
    if (elementTraversed.find(currEle - 1) != elementTraversed.end()) {
      continue;
    }

    int currLcs = 1;
    while (elementTraversed.find(currEle + 1) != elementTraversed.end()) {
      currLcs++;
      currEle++;
    }

    maxValue = max(maxValue, currLcs);
  }

  return maxValue;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << longestConsecutive(nums) << endl;
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

