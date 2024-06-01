/**
 * 1. Occurence Map
 *      Maintain occurence hash and use that to create permutations
 *      Take decision for current element of hash if its count is more than 0
 *        Revert when decision tree comes back
 *      This works this way because we kept map for every position if we have picked specific element
 *        in currPermutation
*/

#include <bits/stdc++.h>

using namespace std;

void permuteUnique(unordered_map<int, int>& nums, int n, int currIndex, vector<int> currPermutation, vector<vector<int>>& ans)
{
  if (currIndex == n) {
    ans.push_back(currPermutation);
    return;
  }

  for (unordered_map<int, int>::iterator i = nums.begin(); i != nums.end(); i++) {
    if (i->second != 0) {
      nums[i->first]--;
      currPermutation.push_back(i->first);

      permuteUnique(nums, n, currIndex + 1, currPermutation, ans);

      currPermutation.pop_back();
      nums[i->first]++;
    }
  }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
  int n = nums.size();

  vector<vector<int>> permutations;
  vector<int> currPermutation;

  unordered_map<int, int> occurence;
  for (int i = 0; i < n; i++) {
    occurence[nums[i]]++;
  }

  permuteUnique(occurence, n, 0, currPermutation, permutations);

  return permutations;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<vector<int>> permutations = permuteUnique(nums);

  for (auto x: permutations) {
    for (int y: x) {
      cout << y << " ";
    }
    cout << endl;
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
