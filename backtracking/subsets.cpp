/**
 * 1. Recursion - O(n*2^n)
 *      Base case: n == 0 => 1 subset, empty array
 *      Subproblem is having subset of array size (n - 1)
 *      Solve: From subsets of (n - 1) size array,
 *        possible subsets would be all subsets of (n - 1) + a[0] attached to all subsets
 *      At each step, we increase number of subsets by 2
 *        hence at each recursive call of size n, 2^n work is done
 *      Time Complexity: T(n) = T(n - 1) + n*2^n ~= O(n*2^n)
 *      Space Complexity: O(n*2^n)
 * 2. Decision Tree Backtracking - O(n*2^n)
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums, int currIndex)
{
  int n = nums.size();

  if (currIndex == n) {
    return vector<vector<int>>(1);
  }

  // ! Size will be 2^n-1
  vector<vector<int>> prevSubsets = subsets(nums, currIndex + 1);

  // ! Takes 2^n-1 operations
  vector<vector<int>> newSubsets(prevSubsets);
  int currSubsetSize = prevSubsets.size();

  // ! Takes 2^n-1 operations
  for (int i = 0; i < currSubsetSize; i++) {
    // ! This copying and appending takes O(n) time
    vector<int> subsetWithCurrElement(prevSubsets[i]);
    subsetWithCurrElement.insert(subsetWithCurrElement.begin(), nums[currIndex]);

    newSubsets.push_back(subsetWithCurrElement);
  }

  // ! At each function call of size n, we did n*2^n work
  return newSubsets;
}

// ! 2. Decision Tree
void subsets2(vector<int>& nums, int currIndex, vector<int> subset, vector<vector<int>>& ans)
{
  if (currIndex >= nums.size()) {
    ans.push_back(subset);
    return;
  }

  // ! Copy of subset is generated to pass hence at each step, we take O(n) time
  subset.push_back(nums[currIndex]);
  subsets2(nums, currIndex + 1, subset, ans);

  subset.pop_back();
  subsets2(nums, currIndex + 1, subset, ans);
}

vector<vector<int>> subsets(vector<int>& nums)
{
  // return subsets(nums, 0);

  // ! Common to pass initial Base data to append to 
  vector<int> subset;
  vector<vector<int>> ans;
  subsets2(nums, 0, subset, ans);

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

  vector<vector<int>> ans = subsets(nums);

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
