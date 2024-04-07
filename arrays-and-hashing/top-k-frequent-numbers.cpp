/**
 * 1. Brute force - O(nlogn)
 *  Created hash for occurence of each number
 *  Generate pair of number and occurence
 *  Sorted the array of pairs in descending and picked top k elements
 * 2. Use heap instead of sort - O(n) + O(klogn)
 *  Instead of sorting, push elements in max heap that would take O(n) for heapify
 *  Pop k elements - O(klogn)
 * 3. Use bucket sort with storage trick - O(n) [Time and space]
 *  Store occurences as same in above methods
 *  Store count as index for array and array value at array index as array
 *  Max array length for bucket sort array would be same as array as
 *    that could be the max number of times a value can repeat
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

// ! 1.
vector<int> topKFrequentBruteForce(vector<int>& nums, int k)
{
  unordered_map<int, int> occurences;

  for (int num: nums) {
    occurences[num]++;
  }

  vector<pp> numOccurencesPair;
  for (unordered_map<int, int>::iterator it = occurences.begin(); it != occurences.end(); it++) {
    numOccurencesPair.push_back(pp(it->first, it->second));
  }

  sort(numOccurencesPair.begin(), numOccurencesPair.end(), [](pp first, pp second) -> bool {
    return first.second > second.second;
  });

  vector<int> ans;
  for (pp occurencePair: vector<pp>(numOccurencesPair.begin(), numOccurencesPair.begin() + k)) {
    ans.push_back(occurencePair.first);
  }

  return ans;
}

// ! 3.
vector<int> topKFrequent(vector<int>& nums, int k)
{
  unordered_map<int, int> occurences;

  for (int num: nums) {
    occurences[num]++;
  }

  int n = nums.size();
  vector<int> bucket[n + 1];

  for (unordered_map<int, int>::iterator it = occurences.begin(); it != occurences.end(); it++) {
    bucket[it->second].push_back(it->first);
  }

  vector<int> ans;

  for (int i = n; i > 0; i--) {
    if (bucket[i].size() != 0) {
      ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
    }
  }

  return vector<int>(ans.begin(), ans.begin() + k);
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> ans = topKFrequent(nums, k);

  for (int num: ans) {
    cout << num << " ";
  }

  cout << endl;
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
