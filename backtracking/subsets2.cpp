/**
 * 1. Naive - O(n*2^n) [T], O(2^n) [S]
 *      Sort array
 *      Generate all subsets and find unique from all them
 *      Use hash or set to push subset to find unique
 * 2. Ignoring multiple same elements - O(n*2^n)
 *      Sort array
 *      Left side of decision tree contains atleast one curr element
 *      Right side of tree should not contain any of the skipped element otherwise it will give duplicate subset
 *        eg. [1, 2, 2, 3] -> If i=1 is skipped in one call and i=2 is skipped is another call, we still get same array
 *            which will yield same subsets hence to avoid it, we skip all
 *      On skip call, find index where same elemets are skipped and call recursively on that index
 *      On include call, simply go with next index
*/

#include <bits/stdc++.h>

using namespace std;

void subsetsWithDup(vector<int>& nums, int currIndex, vector<int> subset, vector<vector<int>>& subsets)
{
  int n = nums.size();

  if (currIndex >= n) {
    subsets.push_back(subset);
    return;
  }

  int newIndex = currIndex + 1;
  while (newIndex < n) {
    if (nums[newIndex] != nums[currIndex]) {
      break;
    }

    newIndex++;
  }

  subsetsWithDup(nums, newIndex, subset, subsets);

  subset.push_back(nums[currIndex]);
  subsetsWithDup(nums, currIndex + 1, subset, subsets);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
  sort(nums.begin(), nums.end());

  vector<vector<int>> ans;
  vector<int> subset;

  subsetsWithDup(nums, 0, subset, ans);

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

  vector<vector<int>> subsets = subsetsWithDup(nums);

  for (auto x: subsets) {
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
