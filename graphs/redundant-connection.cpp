/**
 * 1. Brute force - O(n^2)
 *      DFS on edge list to find cycle
 *        For each node from edge list, need to find neighbor edges where
 *          u will be curr node and v will be other node
 *        Normal DFS cycle detection once neighbors have determined
 *          use visited array and parent to determine cycle
 * 2. Cycle Detection using DFS O(v + e)
 *      Convert edge list to adjacency list graph
 *      Use DFS to detect cycle and return the edge forming the cycle
 * 3. Union Find - O(e) [Used in krushkal algo as well]
 *      Works on edges where parent and rank is maintained
 *      rank keep track of tree/graph size, smaller tree are merged into larger trees
 *      parent keeps track of parent of nodes
 *      If merging edge both nodes have same parent, they will create a cycle
 *        Find parent recursively in parents array till curr != parents[curr]
 *        Merge parents of v1 and v2 based on ranks and assign new parents
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1.
bool dfsEdgeList(vector<vector<int>>& edges, int curr, vector<bool>& visited, int parent, vector<int>& cycleEdge)
{
  visited[curr] = true;

  for (int i = edges.size() - 1; i >= 0; i--) {
    vector<int> edge = edges[i];

    if (edge[0] == curr) {
      if (!visited[edge[1]]) {
        if (dfsEdgeList(edges, edge[1], visited, edge[0], cycleEdge)) {
          cycleEdge = edge;
          return true;
        }

        if (visited[edge[1]] && edge[1] != parent) {
          cycleEdge = edge;
          return true;
        }
      }
    }
  }

  return false;
}

// ! 2.
vector<vector<int>> convertToAdjacenyList(vector<vector<int>>& edges)
{
  int maxNode = INT_MIN;
  for (vector<int> edge: edges) {
    maxNode = max(edge[0], maxNode);
    maxNode = max(edge[1], maxNode);
  }

  vector<vector<int>> graph(maxNode + 1, vector<int>());
  for (vector<int> edge: edges) {
    int v1 = edge[0];
    int v2 = edge[1];

    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }

  return graph;
}

// ! 2.
bool findCycle(vector<vector<int>>& graph, int curr, vector<bool>& visited, int parent, vector<int>& cycleEdge)
{
  visited[curr] = true;

  for (int neighbor: graph[curr]) {
    if (!visited[neighbor]) {
      if (findCycle(graph, neighbor, visited, curr, cycleEdge)) {
        return true;
      }

      if (visited[neighbor] && neighbor != parent) {
        cycleEdge = { curr, neighbor };
        return true;
      }
    }
  }

  return false;
}

// ! 2.
vector<int> findRedundantConnectionAdjList(vector<vector<int>>& edges)
{
  vector<vector<int>> graph = convertToAdjacenyList(edges);
  int n = graph.size();

  vector<bool> visited(n, false);
  vector<int> cycleEdge;

  findCycle(graph, 1, visited, -1, cycleEdge);

  return cycleEdge;
}

// ! 3.
int findParent(int curr, vector<int>& parents) {
  if (curr == parents[curr]) {
    return curr;
  }

  // Updating parent for future. Hence this takes O(1) time not O(v)
  parents[curr] = parents[parents[curr]];

  return findParent(parents[curr], parents);
}

// ! 3.
vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
  int n = edges.size();

  vector<int> parents(n + 1);
  for (int i = 1; i <= n; i++) {
    parents[i] = i;
  }

  vector<int> ranks(n + 1, 1);

  for (int i = 0; i < n; i++) {
    vector<int> edge = edges[i];

    int v1 = edge[0];
    int v2 = edge[1];

    // Find
    int v1Parent = findParent(v1, parents);
    int v2Parent = findParent(v2, parents);

    if (v1Parent == v2Parent) {
      return edge;
    }

    // Union
    if (ranks[v1Parent] > ranks[v2Parent]) {
      parents[v2Parent] = v1Parent;
      ranks[v1Parent] += ranks[v2Parent];
    } else {
      parents[v1Parent] = v2Parent;
      ranks[v2Parent] += v1Parent;
    }
  }

  return vector<int>();
}

void solution()
{
  int e;
  cin >> e;

  vector<vector<int>> edges(e, vector<int>(2));

  for (int i = 0; i < e; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  vector<int> edge = findRedundantConnection(edges);

  cout << edge[0] << " " << edge[1] << endl;
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
