#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

int lastStoneWeightII(vector<int>& stones, int currIndex, int targetSum, unordered_map<string, int>& occured)
{
  int n = stones.size();

  string key = getKey(currIndex, targetSum);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (targetSum < 0) {
    return INT_MAX;
  }

  if (currIndex >= n) {
    return targetSum;
  }

  int includeCurrStone = lastStoneWeightII(stones, currIndex + 1, targetSum - stones[currIndex], occured);
  int notIncludeCurrStone = lastStoneWeightII(stones, currIndex + 1, targetSum, occured);

  occured[key] = min(includeCurrStone, notIncludeCurrStone);

  return occured[key];
}

int lastStoneWeightII(vector<int>& stones)
{
  int n = stones.size();

  int sum = 0;
  for (int stone: stones) {
    sum += stone;
  }

  unordered_map<string, int> occured;

  int leftBagRequired = sum / 2;
  int rightBagRequired = sum - leftBagRequired;

  int leftBagLeftOver = lastStoneWeightII(stones, 0, leftBagRequired, occured);
  int rightBagLeftOver = rightBagRequired - (leftBagRequired - leftBagLeftOver);

  return leftBagLeftOver + rightBagLeftOver;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> stones(n);
  for (int i = 0; i < n; i++) {
    cin >> stones[i];
  }

  cout << lastStoneWeightII(stones) << endl;
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
