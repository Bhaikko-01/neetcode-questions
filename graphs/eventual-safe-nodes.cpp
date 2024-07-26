#include <bits/stdc++.h>

using namespace std;

bool eventualSafeNodes(vector<vector<int>>& graph, int currNode, vector<bool>& visited, unordered_map<int, bool>& dp)
{
  if (visited[currNode]) {
    return dp[currNode];
  }

  visited[currNode] = true;

  if (graph[currNode].size() == 0) {
    dp[currNode] = true;
    return dp[currNode];
  }

  bool neighborsPossible = true;
  for (int neighbor: graph[currNode]) {
    neighborsPossible = neighborsPossible && eventualSafeNodes(graph, neighbor, visited, dp);
  }

  dp[currNode] = neighborsPossible;
  return dp[currNode];
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
  int n = graph.size();

  vector<bool> visisted(n, false);
  unordered_map<int, bool> dp;

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (eventualSafeNodes(graph, i, visisted, dp)) {
      ans.push_back(i);
    }
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> graph(n);

  for (int i = 0; i < n; i++) {
    int edges;
    cin >> edges;

    graph[i] = vector<int>(edges);

    for (int j = 0; j < edges; j++) {
      cin >> graph[i][j];
    }
  }

  vector<int> ans = eventualSafeNodes(graph);

  for (int x: ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main()
{
  solution();

  return 0;
}
