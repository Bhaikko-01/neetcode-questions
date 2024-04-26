/**
 * 1. SAME AS SUBSET 2 where
 *      Sort array
 *      Decision making
 *        In left decision, we include curr element
 *        In right decision, we skip all elements same as curr
 *      If target is zero, that combination is one ans
 *      Else return
*/

#include <bits/stdc++.h>

using namespace std;

void combinationSum2(vector<int>& candidates, int currIndex, int target, vector<int> currCombination, vector<vector<int>>& ans)
{
  int n = candidates.size();

  if (target == 0) {
    ans.push_back(currCombination);
    return;
  }

  if (currIndex >= n || target < 0) {
    return;
  }

  int nextIndex = currIndex + 1;
  while (nextIndex < n) {
    if (candidates[nextIndex] != candidates[currIndex]) {
      break;
    }
    nextIndex++;
  }

  combinationSum2(candidates, nextIndex, target, currCombination, ans);

  currCombination.push_back(candidates[currIndex]);
  combinationSum2(candidates, currIndex + 1, target - candidates[currIndex], currCombination, ans);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
  sort(candidates.begin(), candidates.end());

  vector<vector<int>> ans;
  vector<int> currCombination;

  combinationSum2(candidates, 0, target, currCombination, ans);

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

  vector<vector<int>> ans = combinationSum2(candidates, target);

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
