/**
 * 1. Decision tree of 3 possibility - O(n*3^t) [T], O(n*t) [S]
 *      Since any permutation of array would give same sum, combination in final answer can be repeated
 *      To avoid this, function call with (target - a[0], index + 1) can be avoided
 *        Since this will anyway happen in function call(target, index + 1)
 * 2. Backtrack with 2 possibility - O(n*2^t) [T], O(n*t) [S]
 *      Do function calls with
 *        left tree always including current element and target - ele[current]
 *        right tree never including current element and target
 *
 * Space is O(n*t) because at each iteration, O(n) space is required and depth of tree is k
 *  therefore O(n*k) space
*/

#include <bits/stdc++.h>

using namespace std;

// ! 2.
void combinationSum(vector<int>& candidates, int target, int index, vector<int> numsIncludedTillNow, vector<vector<int>>& ans)
{
  if (target < 0) {
    return;
  }

  if (target == 0) {
    ans.push_back(numsIncludedTillNow);
    return;
  }

  if (index == candidates.size()) {
    return;
  }

  // ! Copy of subset is generated to pass hence at each step, we take O(n) time
  combinationSum(candidates, target, index + 1, numsIncludedTillNow, ans);

  numsIncludedTillNow.push_back(candidates[index]);

  // ! Copy of subset is generated to pass hence at each step, we take O(n) time
  combinationSum(candidates, target - candidates[index], index, numsIncludedTillNow, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> numsTillNow;

  combinationSum(candidates, target, 0, numsTillNow, ans);

  return ans;
}

void solution()
{
  int n, target;
  cin >> n >> target;

  vector<int> candidates(n);
  for (int i = 0; i < n; i++) {
    cin >> candidates[i];
  }

  vector<vector<int>> ans = combinationSum(candidates, target);

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
