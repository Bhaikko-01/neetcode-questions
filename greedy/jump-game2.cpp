/**
 * Problem Similar to jump-game1
 *
 * 1. Backtracking - O(m*n!) [T]
 *      try every combination same as jump-game and get minimum answer
 * 2. DP - O(m*n) [T], O(n) [S]
 *      Memoize repeated work
 * 3. Graph BFS - O(n + n) ~ O(n) [T], O(n) [S]
 *      Since its minimize path problem, BFS can be used
 *      Graph will have each index as vertex and its reach by nums[i] as edges to other vertex
 *      Run BFS to find shortest distance
 *        Make sure, neighbor does not exceed n when using nums[i] + reach
 *    Note: Need not create graph and find neighbor dynamically using reach and currIndex
*/

#include <bits/stdc++.h>

using namespace std;

int jumpGraph(vector<int>& nums)
{
  int n = nums.size();

  vector<vector<int>> graph(n, vector<int>());
  vector<bool> visited(n, false);

  for (int i = 0; i < n; i++) {
    for (int reach = 1; reach <= nums[i] && i + reach < n; reach++) {
      graph[i].push_back(i + reach);
    }
  }

  int jumpSteps = 0;
  queue<int> pending;

  // src = 0, dest = n - 1
  pending.push(0);

  while (!pending.empty()) {
    int currLevelSize = pending.size();
    for (int i = 1; i <= currLevelSize; i++) {
      int curr = pending.front();
      pending.pop();

      if (curr == n - 1) {
        return jumpSteps;
      }

      for (int neighbor: graph[curr]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          pending.push(neighbor);
        }
      }
    }

    jumpSteps++;
  }

  return jumpSteps;
}

int jump(vector<int>& nums)
{
  int n = nums.size();

  vector<bool> visited(n, false);

  int jumpSteps = 0;
  queue<int> pending;

  // src = 0, dest = n - 1
  pending.push(0);

  while (!pending.empty()) {
    int currLevelSize = pending.size();
    for (int i = 1; i <= currLevelSize; i++) {
      int curr = pending.front();
      pending.pop();

      if (curr == n - 1) {
        return jumpSteps;
      }

      for (int reach = 1; reach <= nums[curr] && curr + reach < n; reach++) {
        int neighbor = curr + reach;

        if (!visited[neighbor]) {
          visited[neighbor] = true;
          pending.push(neighbor);
        }
      }
    }

    jumpSteps++;
  }

  return jumpSteps;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << jump(nums) << endl;
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
