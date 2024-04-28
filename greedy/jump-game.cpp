/**
 * 1. Backtracking - O(m*n^n) ~ O(m*n!) [T], O(n) [S]
 *      Backtrack with all possible steps of current index value
 *      If last index is reached then we found ans
 *      Otherwise no answer found
 * 2. Memoize - O(m*n) [T], O(n) [S]
 *      Memoize index so we dont traverse for that index again
 * 3. Greedy - O(n) [T]
 *      Iterate from end and check if last index as goal can be reached by indexes than that goalIndex
 *      if goal can be reached
 *        mark goal = i
 *      goal Reachable if goal == 0;
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1
bool canJumBrute(vector<int>& nums, int currIndex)
{
  int n = nums.size();

  if (currIndex == n - 1) {
    return true;
  }

  if (currIndex >= n) {
    return false;
  }

  int possibleSteps = nums[currIndex];

  if (possibleSteps == 0) {
    return false;
  }

  for (int i = 1; i <= possibleSteps; i++) {
    if (canJumBrute(nums, currIndex + i)) {
      return true;
    }
  }

  return false;
}

// ! 1
bool canJumBrute(vector<int>& nums)
{
  return canJumBrute(nums, 0);
}

// ! 2
bool canJumpMemo(vector<int>& nums, int currIndex, unordered_map<int, bool>& occured)
{
  int n = nums.size();

  if (occured.find(currIndex) != occured.end()) {
    return occured[currIndex];
  }

  if (currIndex == n - 1) {
    return true;
  }

  if (currIndex >= n) {
    return false;
  }

  int possibleSteps = nums[currIndex];

  if (possibleSteps == 0) {
    return false;
  }

  for (int i = 1; i <= possibleSteps; i++) {
    occured[currIndex + i] = canJumpMemo(nums, currIndex + i, occured);
    if (occured[currIndex + i]) {
      return true;
    }
  }

  return false;
}

// ! 2
bool canJumpMemo(vector<int>& nums)
{
  unordered_map<int, bool> occured;

  return canJumpMemo(nums, 0, occured);
}

bool canJump(vector<int>& nums)
{
  int n = nums.size();

  int goal = n - 1;
  int i = n - 2;

  while (i >= 0) {
    if (i + nums[i] >= goal) {
      goal = i;
    }
    i--;
  }

  return goal == 0;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << canJump(nums) << endl;
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
