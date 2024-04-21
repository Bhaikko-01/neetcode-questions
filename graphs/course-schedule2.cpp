/**
 * 1. Topological Sort
 *      Generate graph based on courses where
 *        u is course required to finish
 *        v is current course
 *      Generate topological sort in which u will occur before v if there is edge from u to v
 *        use stack to generate sort
 *      If cycle is detected then no need to generate sort as not possible
*/

#include <bits/stdc++.h>

using namespace std;

bool topoSort(vector<vector<int>>& graph, int curr, vector<bool>& visited, vector<bool>& recVisited, stack<int>& topoSortStack)
{
  visited[curr] = true;
  recVisited[curr] = true;

  for (int neighbor: graph[curr]) {
    if (!visited[neighbor]) {
      if (topoSort(graph, neighbor, visited, recVisited, topoSortStack)) {
        return true;
      }
    }

    if (visited[neighbor] && recVisited[neighbor]) {
      return true;
    }
  }

  topoSortStack.push(curr);
  recVisited[curr] = false;
  return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
  vector<vector<int>> graph(numCourses, vector<int>());

  int n = prerequisites.size();
  for (vector<int> edge: prerequisites) {
    int n1 = edge[0];
    int n2 = edge[1];

    graph[n2].push_back(n1);
  }

  vector<bool> visited(numCourses, false);
  vector<bool> recVisited(numCourses, false);
  stack<int> topoSortStack;
  vector<int> ans;

  for (int i = 0; i < numCourses; i++) {
    if (!visited[i]) {
      if (topoSort(graph, i, visited, recVisited, topoSortStack)) {
        return ans;
      }
    }
  }

  while (!topoSortStack.empty()) {
    ans.push_back(topoSortStack.top());
    topoSortStack.pop();
  }

  return ans;
}

void solution()
{
  int numCourses, e;
  cin >> numCourses >> e;

  vector<vector<int>> prerequisites(e, vector<int>(2));
  for (int i = 0; i < e; i++) {
    cin >> prerequisites[i][0] >> prerequisites[i][1];
  }

  vector<int> ans = findOrder(numCourses, prerequisites);
  for (int a: ans) {
    cout << a << " ";
  }

  cout << endl;
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
