/**
 * Dikjstra works on both Directed and adirected graph
 *  Used to find shortest distance from one node to all other nodes
 *  Each node in graph is relaxed to find minDistance from source node
 *    distance[v] = min(distance[v], edge[u][v] + distance[u])
 *  Node with the least distance from source is selected and all neighbors using this node is relaxed (BFS)
 *    Heap can be used to arrange nodes based on distance from source
 * Dont process nodes that are processed, use isVisited array
 * Only works for graphs having nonnegative weight cycle
 * Time complexity - O((E + V)logV)
 *  inserting V nodes into minheap O(VlogV)
 *  pop minVertex from min Heap - O(logV)
 *  Process all vertices and neighbors atmost once like in BFS and push neighbors - O((V + E)logV)
 * Space Complexity - O(V + E)
*/

#include "bits/stdc++.h"

using namespace std;

struct Neighbor {
  int destination;
  int weight;
};

struct Vertex {
  int source;
  int distance;
  vector<Neighbor*> neighbors;
};

struct MinDistanceVertexComparator {
  bool operator()(Vertex* first, Vertex* second) {
    return first->distance > second->distance;
  }
};

int dikjstra(vector<vector<int>>& times, int n, int k)
{
  int m = times.size();

  vector<Vertex*> graph(n + 1);
  vector<bool> visited(n + 1, false);
  for (int i = 1; i <= n; i++) {
    graph[i] = new Vertex({ i, INT_MAX });
  }

  for (vector<int> time: times) {
    int src = time[0];
    int dest = time[1];
    int weight = time[2];

    Vertex* vertex = graph[src];
    vertex->neighbors.push_back(new Neighbor({ dest, weight }));
  }

  priority_queue<Vertex*, vector<Vertex*>, MinDistanceVertexComparator> pending;
  pending.push(graph[k]);
  graph[k]->distance = 0;

  while (!pending.empty()) {
    Vertex* currVertex = pending.top();
    pending.pop();

    if (visited[currVertex->source]) {
      continue;
    }

    visited[currVertex->source] = true;

    for (Neighbor* neighbor: currVertex->neighbors) {
      Vertex* neighborVertex = graph[neighbor->destination];

      int currDistance = currVertex->distance + neighbor->weight;
      if (currDistance < neighborVertex->distance) {
        neighborVertex->distance = currDistance;
      }

      pending.push(neighborVertex);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << i << " " << graph[i]->distance << endl;
  }
}
