/**
 * 1. DFS - O(V + E)
 *      Maintain isVisited for each node and check if it is reached again
 *      Make sure, neighbor is not same node from which we reached current code,
 *        pass currNode as parent as well to DFS of neighbor
*/

#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<int> adj[], int V, vector<bool>& visited, int curr, int parent)
{
  visited[curr] = true;

  for (int neighbour: adj[curr]) {
    if (!visited[neighbour]) {
      if (dfs(adj, V, visited, neighbour, curr)) {
        return true;
      }
    } else if (neighbour != parent) {
      return true;
    }
  }

  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  vector<bool> visited(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i] && dfs(adj, V, visited, i, -1)) {
      return true;
    }
  }

  return false;
}

void solution()
{
  
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
