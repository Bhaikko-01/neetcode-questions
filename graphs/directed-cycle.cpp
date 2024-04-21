/**
 * 1. DFS - O(V + E)
 *      maintain isVisited and recStack
 *        each DFS is treated independent of isVisited array hence for each DFS
 *          recStack is maintained and any element occuring twice in recStack is considered in cycle
 *        Other code works same as undirected code
 *        no need to maintain parent as
 *          directed graph so edge to parent required explicitly
 *        If visited[neighbour] && recStack[neightbour] then cycle exists
 *        Mark recStack[curr] as false if cycle not detected in currNode
*/

#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<int> adj[], int V, vector<bool>& visited, vector<bool>& recVisited, int curr)
{
  visited[curr] = true;
  recVisited[curr] = true;

  for (int neighbour: adj[curr]) {
    if (!visited[neighbour]) {
      if (dfs(adj, V, visited, recVisited, neighbour)) {
        return true;
      }
    } else if (visited[neighbour] && recVisited[neighbour]) {
      return true;
    }
  }

  recVisited[curr] = false;
  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  vector<bool> visited(V, false);
  vector<bool> recVisited(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i] && dfs(adj, V, visited, recVisited, i)) {
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
