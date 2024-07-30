/**
 * 1. Backtracking - O(n!)
 *      At each level of tree, we have current permutation
 *        which is permutations possible till that currIndex
 *      We insert currIndex at all indexes of currPermutationa and recursively call permute on that currPermutation
 *      If currIndex >= n, currPermutation is one possible permutation
 *      At each level,
 *        we do O(n) work of copying and inserting element for currPermutation - O(n^2)
 *        At each level, there will be x! iterations where x is depth of tree. Max depth of tree is n!
 *        T(n) = (1! + 2! + 3! + ---) * n^2 ~ O(n^n) ~ O(n!)
*/

#include <bits/stdc++.h>

using namespace std;

void permute(vector<int>& nums, int currIndex, vector<int> currPermutation, vector<vector<int>>& ans)
{
  if (currIndex >= nums.size()) {
    ans.push_back(currPermutation);
    return;
  }

  int n = currPermutation.size();
  for (int i = 0; i <= n; i++) {
    vector<int> newPermutation(currPermutation);
    newPermutation.insert(newPermutation.begin() + i, nums[currIndex]);

    permute(nums, currIndex + 1, newPermutation, ans);
  }
}

vector<vector<int>> permute(vector<int>& nums)
{
  vector<vector<int>> ans;

  permute(nums, 0, vector<int>(0), ans);

  return ans;
}

// ! 2.
void permute(vector<int>& nums, vector<int> currPermutation, vector<vector<int>>& ans, vector<bool>& picked) {
  int n = nums.size();

  if (currPermutation.size() == n) {
    ans.push_back(currPermutation);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!picked[i]) {
      picked[i] = true;
      currPermutation.push_back(nums[i]);

      permute(nums, currPermutation, ans, picked);

      currPermutation.pop_back();
      picked[i] = false;
    }
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> ans;
  int n = nums.size();
  vector<bool> picked(n, false);

  permute(nums, vector<int>(0), ans, picked);

  return ans;
}


void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<vector<int>> ans = permute(nums);

  for (auto x: ans) {
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
