/**
 * 1. Directed graph Cycle detection
 *      Generate graph based on courses where
 *        u is course required to finish
 *        v is current course
 *      Run DFS to detect cycle using visited and recVisited array
 *        as this will be directed graph
*/

#include <bits/stdc++.h>

using namespace std;

bool isDirectedCycle(vector<vector<int>>& graph, int curr, vector<bool>& visited, vector<bool>& recVisited)
{
  visited[curr] = true;
  recVisited[curr] = true;

  for (int neighbor: graph[curr]) {
    if (!visited[neighbor]) {
      if (isDirectedCycle(graph, neighbor, visited, recVisited)) {
        return true;
      }
    } else if (visited[neighbor] && recVisited[neighbor]) {
      return true;
    }
  }

  recVisited[curr] = false;
  return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
  vector<vector<int>> graph(numCourses, vector<int>());

  int n = prerequisites.size();
  for (vector<int> edge: prerequisites) {
    int n1 = edge[0];
    int n2 = edge[1];

    graph[n1].push_back(n2);
  }

  vector<bool> visited(numCourses, false);
  vector<bool> recVisited(numCourses, false);

  for (int i = 0; i < numCourses; i++) {
    if (!visited[i]) {
      if (isDirectedCycle(graph, i, visited, recVisited)) {
        return false;
      }
    }
  }

  return true;
}

void solution()
{
  int numCourses, e;
  cin >> numCourses >> e;

  vector<vector<int>> prerequisites(e, vector<int>(2));
  for (int i = 0; i < e; i++) {
    cin >> prerequisites[i][0] >> prerequisites[i][1];
  }

  cout << canFinish(numCourses, prerequisites) << endl;
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
