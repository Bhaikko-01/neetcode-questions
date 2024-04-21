/**
 * 1. Djikstra - O((E + V)logV)
 *      Since we need to reach every single node, we are using Djikstra to find distance to all nodes from source node
 *      Run djikstra to find distance to all nodes from source
 *      Max distance from source is answer in all distances
 * Note: Instead of creating Vertex and Neighbor class,
 *  priority_queue can have pair of { distance, node } where distance is from source and node neighbor
*/

#include <bits/stdc++.h>

using namespace std;

// { node, distance } / { dest, weight }
typedef pair<int, int> pp;

struct MinDistanceVertexComparator {
  bool operator()(pp first, pp second) {
    // Comparing distance from source
    return first.second > second.second;
  }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
  int m = times.size();

  vector<vector<pp>> graph(n + 1, vector<pp>());
  vector<bool> visited(n + 1, false);
  vector<int> distances(n + 1, INT_MAX);

  for (vector<int> time: times) {
    int src = time[0];
    int dest = time[1];
    int weight = time[2];

    graph[src].push_back(pp({ dest, weight }));
  }

  priority_queue<pp, vector<pp>, MinDistanceVertexComparator> pending;
  pending.push(pp({ k, 0 }));
  distances[k] = 0;

  while (!pending.empty()) {
    pp currVertex = pending.top();
    pending.pop();

    int nodeVal = currVertex.first;

    if (visited[nodeVal]) {
      continue;
    }

    visited[nodeVal] = true;

    for (pp neighbor: graph[nodeVal]) {
      int vertex = neighbor.first;
      int weight = neighbor.second;

      int currDistance = distances[nodeVal] + weight;
      if (currDistance < distances[vertex]) {
        distances[vertex] = currDistance;
      }

      pending.push({ vertex, currDistance });
    }
  }

  int delay = INT_MIN;
  for (int i = 1; i <= n; i++) {
    if (distances[i] == INT_MAX) {
      return -1;
    }

    delay = max(distances[i], delay);
  }

  return delay;
}

void solution()
{
  int m, n, k;
  cin >> m >> n >> k;

  vector<vector<int>> times(m, vector<int>(3));
  for (int i = 0; i < m; i++) {
    cin >> times[i][0] >> times[i][1] >> times[i][2];
  }

  cout << networkDelayTime(times, n, k) << endl;
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
