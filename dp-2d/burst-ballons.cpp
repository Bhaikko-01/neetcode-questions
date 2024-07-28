/**
 * 1. Brute Force - O(n!)
 *      For each iteration, try popping ballon while keeping track of burst ballons
 *      Find prevI and nextI using popped ballons and out of bound indexes
 *        skip if current is already popped
 *      This cannot be memoized as we are techincally doing subsequence approach where decision is made
 *        this will give O(2^n) choices and no subproblem to memoize with
 * 2. Subarray - O(n^3) // Processing n^2 subarrays n times
 *      Instead of popping current element first, we will pop it last while popping left and right subarrays
 *      Current recursion will traverse from l <= i <= r
 *        leftValue = l - 1 >= 0 ? nums[l - 1] : 1
 *        rightValue = r + 1 < n ? nums[r + 1] : 1
 *        currValue = leftValue * nums[i] * rightValue
 *      Call recursion on left subarray and right subarray
 *        maxCoins(nums, l, i - 1) // left subarray
 *        maxCoins(nums, i + 1, r) // right subarray
 */

#include <bits/stdc++.h>

using namespace std;

// ! 1.
int maxCoins(vector<int>& nums, vector<int>& popped, int left)
{
  int n = nums.size();

  if (left == 0) {
    return 0;
  }

  int currMaxPopValue = 0;

  for (int i = 0; i < n; i++) {
    if (popped[i]) {
      continue;
    }

    int prevI = i - 1;
    while (prevI >= 0 && popped[prevI]) {
      prevI--;
    }

    int nextI = i + 1;
    while (nextI < n && popped[nextI]) {
      nextI++;
    }

    int prevValue = prevI < 0 ? 1 : nums[prevI];
    int nextValue = nextI < n ? nums[nextI] : 1;

    popped[i] = true;
    int currPoppedValue = prevValue * nextValue * nums[i] + maxCoins(nums, popped, left - 1);

    currMaxPopValue = max(currMaxPopValue, currPoppedValue);
    popped[i] = false;
  }

  return currMaxPopValue;
}

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

// ! 2.
int maxCoins(vector<int>& nums, int l, int r, unordered_map<string, int>& occured)
{
  if (l > r) {
    return 0;
  }

  int n = nums.size();

  string key = getKey(l, r);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  int currMax = 0;

  for (int i = l; i <= r; i++) {
    int prevI = l - 1 >= 0 ? nums[l - 1] : 1;
    int nextI = r + 1 < n ? nums[r + 1] : 1;

    int currPoppedLast = prevI * nums[i] * nextI;
    int currAns = currPoppedLast + maxCoins(nums, l, i - 1, occured) + maxCoins(nums, i + 1, r, occured);

    currMax = max(currMax, currAns);
  }

  occured[key] = currMax;

  return occured[key];
}

int maxCoins(vector<int>& nums)
{
  int n = nums.size();

  // vector<int> popped(n, false);
  // return maxCoins(nums, popped, n);

  unordered_map<string, int> occured;

  return maxCoins(nums, 0, n - 1, occured);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxCoins(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
