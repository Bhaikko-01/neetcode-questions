/**
 * 1. DFS - O(n)
 *      Convert the arrays into tree data structure
 *      Run DFS that would return max time by considering all children of node
 *        Return maxTime at one node plus the time that node will take
 */

#include <bits/stdc++.h>

using namespace std;

int numOfMinutes(vector<vector<int>>&tree, int headID, vector<int>& informTime)
{
  vector<int> currSuboordinates = tree[headID];

  if (currSuboordinates.size() == 0) {
    return 0;
  }

  int subordinateMaxTime = 0;

  for (int suboordinate: currSuboordinates) {
    subordinateMaxTime = max(subordinateMaxTime, numOfMinutes(tree, suboordinate, informTime));
  }

  return subordinateMaxTime + informTime[headID];
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
{
  queue<int> pending;
  pending.push(headID);

  int timeTaken = 0;

  vector<vector<int>> subordinatesMapping(n, vector<int>());
  for (int i = 0; i < n; i++) {
    if (headID == i) {
      continue;
    }

    subordinatesMapping[manager[i]].push_back(i);
  }

  return numOfMinutes(subordinatesMapping, headID, informTime);
}

void solution()
{
  int n, headID;
  cin >> n >> headID;

  vector<int> manager(n), informTime(n);
  for (int i = 0; i < n; i++) {
    cin >> manager[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> informTime[i];
  }

  cout << numOfMinutes(n, headID, manager, informTime) << endl;
}

int main()
{
  solution();

  return 0;
}
