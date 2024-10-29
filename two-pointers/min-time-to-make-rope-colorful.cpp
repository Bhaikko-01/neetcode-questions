/**
 * 1. Two Pointer - O(n)
 *      Find subarray that contains duplicate ballon colors
 *      Get min cost for that subarray by
 *        finding max value from that subarray
 *        subtract that from sum of subarray
 *        This works because we want to minimize cost of this subarray popping
 *        So need (sum of all minValues except one) OR sum - maxValue
 *      Do above for all subarrays
 */

#include <bits/stdc++.h>

using namespace std;

int minCostOfPartition(vector<int>& neededTime, int start, int end)
{
  int cost = 0;
  int maxIndex = start;

  for (int i = start; i <= end; i++) {
    if (neededTime[i] >= neededTime[maxIndex]) {
      maxIndex = i;
    }

    cost += neededTime[i];
  }

  return cost - neededTime[maxIndex];
}

int minCost(string colors, vector<int>& neededTime)
{
  int n = neededTime.size();
  int cost = 0;

  char currentColor = colors[0];
  int start = 0,
      end = 0;

  for (int i = 1; i < n; i++) {
    if (colors[i] == currentColor) {
      end++;
    } else {
      cost += minCostOfPartition(neededTime, start, end);
      start = i;
      end = i;
      currentColor = colors[i];
    }
  }

  if (start != end) {
    cost += minCostOfPartition(neededTime, start, end);
  }

  return cost;
}

void solution()
{
  int n;
  cin >> n;

  string colors;
  cin >> colors;

  vector<int> neededTime(n);
  for (int i = 0; i < n; i++) {
    cin >> neededTime[i];
  }

  cout << minCost(colors, neededTime) << endl;
}

int main()
{
  solution();

  return 0;
}
