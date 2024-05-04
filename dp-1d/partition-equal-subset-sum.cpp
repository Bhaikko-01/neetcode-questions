/**
 * Since need to find two sub-arrays with same sum
 *  Find total sum and find a subsequence that contains half sum
 *  No need to find subsequence if Sum is odd as not possible
*/

#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

bool canPartition(vector<int>& nums, int currIndex, int sum, unordered_map<string, bool>& occured)
{
  int n = nums.size();

  string key = getKey(currIndex, sum);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (sum == 0) {
    return true;
  }

  if (currIndex >= n || sum < 0) {
    return false;
  }

  bool includeCurrEle = canPartition(nums, currIndex + 1, sum - nums[currIndex], occured);
  bool notIncludeCurrEle = canPartition(nums, currIndex + 1, sum, occured);

  occured[key] = includeCurrEle || notIncludeCurrEle;

  return occured[key];
}

bool canPartitionDP(vector<int>& nums, int sum)
{
  int n = nums.size();

  vector<vector<int>> dp(sum + 1, vector<int>(n + 1, false));

  for (int i = 0; i < n; i++) {
    dp[0][i] = true;
  }

  for (int currSum = 1; currSum <= sum; currSum++) {
    for (int i = n - 1; i >= 0; i--) {
      bool includeCurrEle = false;

      int remAmount = currSum - nums[i];
      if (remAmount >= 0) {
        includeCurrEle = dp[currSum - nums[i]][i + 1];
      }

      bool notIncludeCurrEle = dp[currSum][i + 1];

      dp[currSum][i] = includeCurrEle || notIncludeCurrEle;
    }
  }

  return dp[sum][0];
}

bool canPartition(vector<int>& nums)
{
  int n = nums.size();

  int totalSum = 0;
  for (int x: nums) {
    totalSum += x;
  }

  if (totalSum & 1) {
    return false;
  }

  int reqSum = totalSum / 2;

  unordered_map<string, bool> occured;

  // return canPartition(nums, 0, reqSum, occured);
  return canPartitionDP(nums, reqSum);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << canPartition(nums) << endl;
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
