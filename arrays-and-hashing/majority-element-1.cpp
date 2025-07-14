/**
 * 1. Maintain frequency HashMap - O(n) [T + S]
 *
 * 2. Maintain majorityEl and majorityCount (Boyer-Moore) - O(n) [t]
 *      for every el,
 *        if el is same as majorityEl then majorityCount++
 *        else majorityCount--
 *      This works as it is guaranteed that an element exists with more than (n/2) frequency
 *      Last majorityEl is answer
 *      Note: This algo only works if it is guranteed that array will have majority element
 */

#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> nums)
{
  int n = nums.size();

  int currMajorityEl = 0;
  int currMajority = 0;

  for (int num: nums) {
    if (currMajority == 0) {
      currMajorityEl = num;
    }

    if (currMajorityEl == num) {
      currMajority++;
    } else {
      currMajority--;
    }
  }

  return currMajorityEl;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << majorityElement(nums) << endl;
}

int main()
{
  solution();

  return 0;
}

