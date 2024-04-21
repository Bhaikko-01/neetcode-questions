/**
 * All pairs shortest path can be evaluated with Floyd Warshal algo
 *  At each iteration, we calculate path for each node through another node
 *    Ai is calculating path of all vertex to vertex pair through node i
 * If i is same as path one of the two nodes then no computation required
 * Else dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
 * Time complexity - O(n^3)
 * Space - O(1)
*/

#include <bits/stdc++.h>

using namespace std;

void floydWarshal(vector<vector<int>>& graph)
{
  int n = graph.size();

  vector<vector<int>> distances(graph);

  // Distance from node to current node is 0 as no self loop
  for (int i = 0; i < n; i++) {
    distances[i][i] = 0;
  }

  for (int throughNode = 0; throughNode < n; throughNode++) {
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        // Skipping if one of the node is same as through node
        if (u == throughNode || v == throughNode) {
          continue;
        }

        // No edge exists so no point of calculating distance
        // -1 is treated if no edge between two vertices
        if (distances[u][throughNode] == -1 || distances[throughNode][v] == -1) {
          continue;
        }

        int currDistanceThroughNode = distances[u][throughNode] + distances[throughNode][v];

        // First condition as there is a valid distance through k from u to v so we update distance anyway
        if (distances[u][v] == -1 || currDistanceThroughNode < distances[u][v]) {
          distances[u][v] = currDistanceThroughNode;
        }
      }
    }
  }

  cout << endl;
  for (auto x: distances) {
    for (int y: x) {
      cout << y << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> graph(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }

  floydWarshal(graph);
}
