/**
 * Linear ordering of graph vertices such that for every directed edge uv
 *  from vertex u to vertex v, u comes before v in the ordering
 * Applicable on Directed Acyclic graph and is not unique
 * Unique will be if every vertex has only one out-degree
 *
 * ALGO
 * Run DFS on each node
 *  push to stack when that node and its all neighbor are processed
 *  final stack will have topological sort
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], int V, int curr, stack<int>& topoSortStack, vector<bool>& visited)
{
  if (visited[curr]) {
    return;
  }

  visited[curr] = true;

  for (int neighbor: adj[curr]) {
    dfs(adj, V, neighbor, topoSortStack, visited);
  }

  topoSortStack.push(curr);
}

vector<int> topoSort(int V, vector<int> adj[])
{
  vector<bool> visited(V, false);
  stack<int> topoSortStack;

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs(adj, V, i, topoSortStack, visited);
    }
  }

  vector<int> topoSortOrder;
  while (!topoSortStack.empty()) {
    topoSortOrder.push_back(topoSortStack.top());
    topoSortStack.pop();
  }

  return topoSortOrder;
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
