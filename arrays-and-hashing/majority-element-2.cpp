/**
 * 1. Boyer Moore Algo - O(n) [T], O(1) [S]
 *      Note: Its only possible for max 2 elements to have frequency more than floor(n/3)
 *      Maintain two elements like in majority-element-1
 *      To easily maintain two numbers and edge cases, better to use hashmap for this whose size never exceeds 2
 *        If element other than those two are encountered, we decrease frequency
 *        Else, increase frequency of correct number
 *      In end, hashMap will have two numbers. Their frequency should be checked if its actually greater than floor(n/3)
 *        to check if most frequent elements till now actually have correct frequency
 */

#include <bits/stdc++.h>

using namespace std;

bool hasThresholdFreq(vector<int>& nums, int check)
{
  int n = nums.size();

  int threshold = n / 3;
  int count = 0;

  for (int num: nums) {
    if (num == check) {
      count++;
    }
  }

  return count > threshold;
}

vector<int> majorityElement(vector<int>& nums)
{
  int n = nums.size();
  vector<int> ans;

  unordered_map<int, int> freqMap;

  for (int num: nums) {
    freqMap[num]++;

    if (freqMap.size() >= 3) {
      unordered_map<int, int> newFreqMap;

      for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
        int newFreq = it->second - 1;

        if (newFreq >= 1) {
          newFreqMap[it->first] = newFreq;
        }
      }

      freqMap = newFreqMap;
    }
  }

  for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
    if (hasThresholdFreq(nums, it->first)) {
      ans.push_back(it->first);
    }
  }

  return ans;
}

/**
 * 2 1 1 3 1 4 5 6
 * {
 *  2: 1
 *  1: 2
 * }
 */

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> ans = majorityElement(nums);
  for (int num: ans) {
    cout << num << " ";
  }
  cout << endl;
}

int main()
{
  solution();

  return 0;
}
