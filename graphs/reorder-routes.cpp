/**
 * 1. BFS - O(n)
 *      Convert edge list to graph adjacency list
 *        Maintain reversed graph which signifies which nodes can reach 0 if there is an edge from 0 to that node
 *          in reversed graph
 *      Run BFS such that
 *        all nodes reachable by 0 will need to have their edge inverted - determined by graph
 *          everytime a neighbor is added, count++
 *        all nodes reachable by 0 using reverse graph already have edge from that node to 0
 *          so no need to increase count
*/

#include <bits/stdc++.h>

using namespace std;

int minReorder(int n, vector<vector<int>>& connections)
{
  vector<vector<int>> graph(n, vector<int>()),
                      reverseGraph(n, vector<int>());

  for (vector<int> connection: connections) {
    graph[connection[0]].push_back(connection[1]);
    reverseGraph[connection[1]].push_back(connection[0]);
  }

  int count = 0;
  queue<int> pending;

  pending.push(0);

  vector<int> visited(n, false);
  visited[0] = true;

  while (!pending.empty()) {
    int currLevelSize = pending.size();

    for (int i = 1; i <= currLevelSize; i++) {
      int curr = pending.front();
      pending.pop();

      for (int neighbor: graph[curr]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          count++;

          pending.push(neighbor);
        }
      }

      for (int neighbor: reverseGraph[curr]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          pending.push(neighbor);
        }
      }
    }
  }

  return count;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> connections(n - 1, vector<int>(2));

  for (int i = 0; i < n - 1; i++) {
    cin >> connections[i][0] >> connections[i][1];
  }

  cout << minReorder(n, connections) << endl;
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
