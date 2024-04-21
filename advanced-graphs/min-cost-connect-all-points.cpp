/**
 * 1. Krushkal Algo - O(n^2 + n^2logn)
 *      Convert points into nodes using unique key
 *      Convert nodes into edge list and weight as manhattan distance
 *      Apply krushkal algo to get Edges for MST
 *        Sort edges based on increasing order of weights
 *        Pick edges till (n - 1) edges picked
 *          If picked edge creates a cycle using Union find algo, the edge cannot be picked
 *          Else pick the edge
 *      Get sum of all MST edges for total cost
*/

#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
  string v1Key;
  string v2Key;
  int weight;

public:
  Edge(string v1Key, string v2Key, int weight) {
    this->v1Key = v1Key;
    this->v2Key = v2Key;
    this->weight = weight;
  }
};

string generateKey(vector<int>& point)
{
  return to_string(point[0]) + "," + to_string(point[1]);
}

int calculateManhattanDistance(vector<int>& point1, vector<int>& point2)
{
  return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
}

struct MinEdgeHeapComparator {
  bool operator()(Edge a, Edge b) {
    return a.weight > b.weight;
  }
};

string findParent(string nodeKey, unordered_map<string, string>& parents)
{
  if (nodeKey == parents[nodeKey]) {
    return nodeKey;
  }

  parents[nodeKey] = parents[parents[nodeKey]];

  return findParent(parents[nodeKey], parents);
}

int minCostConnectPoints(vector<vector<int>>& points)
{
  int n = points.size();

  vector<Edge> edges;

  int currEdges = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      Edge edge = Edge(
        generateKey(points[i]),
        generateKey(points[j]),
        calculateManhattanDistance(points[i], points[j])
      );

      edges.push_back(edge);
    }
  }

  sort(edges.begin(), edges.end(), [](Edge first, Edge second) -> bool {
    return first.weight < second.weight;
  });

  unordered_map<string, string> parents;
  unordered_map<string, int> ranks;
  for (vector<int> point: points) {
    string nodeKey = generateKey(point);
    parents[nodeKey] = nodeKey;
    ranks[nodeKey] = 1;
  }

  vector<Edge> mstEdges;
  int edgeIndex = 0;

  while (currEdges != n - 1) {
    Edge edge = edges[edgeIndex];
    edgeIndex++;

    string v1 = edge.v1Key;
    string v2 = edge.v2Key;

    string v1Parent = findParent(v1, parents);
    string v2Parent = findParent(v2, parents);

    // IF v1Parent and v2Parent is same then edge cannot be considered
    if (v1Parent != v2Parent) {
      if (ranks[v1Parent] < ranks[v2Parent]) {
        parents[v1Parent] = v2Parent;
        ranks[v2Parent] += ranks[v1Parent];
      } else {
        parents[v2Parent] = v1Parent;
        ranks[v1Parent] += ranks[v2Parent];
      }

      currEdges++;
      mstEdges.push_back(edge);
    }
  }

  int minCost = 0;
  for (Edge edge: mstEdges) {
    minCost += edge.weight;
  }

  return minCost;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> points(n, vector<int>(2));

  for (int i = 0; i < n; i++) {
    cin >> points[i][0] >> points[i][1];
  }

  cout << minCostConnectPoints(points) << endl;
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
