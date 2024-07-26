#include <bits/stdc++.h>

using namespace std;

void topoSortDfs(vector<vector<int>>& graph, int currVertex, vector<bool>& isVisited, stack<int>& topoSorted)
{
  isVisited[currVertex] = true;

  for (int neighbor: graph[currVertex]) {
    if (!isVisited[neighbor]) {
      topoSortDfs(graph, neighbor, isVisited, topoSorted);
    }
  }

  topoSorted.push(currVertex);
}

int findIndex(vector<int>& arr, int el)
{
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if (arr[i] == el) {
      return i;
    }
  }

  return -1;
}

bool findCourseQuery(vector<int> topoSorts, int first, int second)
{
  int n = topoSorts.size();

  int firstIndex = findIndex(topoSorts, first);
  int secondIndex = findIndex(topoSorts, second);

  cout << endl;
  cout << first << " " << firstIndex << endl;
  cout << second << " " << secondIndex << endl;
  cout << endl;

  if (firstIndex == -1 || secondIndex == -1) {
    return false;
  }

  return firstIndex < secondIndex;
}

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
{
  vector<vector<int>> graph(numCourses, vector<int>());

  int n = prerequisites.size();
  for (int i = 0; i < n; i++) {
    graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
  }

  vector<int> topoSort;
  vector<bool> isVisited(numCourses, false);
  stack<int> currSort;

  for (int i = 0; i < numCourses; i++) {

    if (!isVisited[i]) {
      topoSortDfs(graph, i, isVisited, currSort);
    }
  }

  while (!currSort.empty()) {
    topoSort.push_back(currSort.top());
    currSort.pop();
  }

  vector<bool> ans;
  int m = queries.size();

  for (int i = 0; i < m; i++) {
    bool currAns = findCourseQuery(topoSort, queries[i][0], queries[i][1]);

    ans.push_back(currAns);
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  int m;
  cin >> m;

  vector<vector<int>> prerequisites(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    cin >> prerequisites[i][0] >> prerequisites[i][1];
  }

  cin >> m;

  vector<vector<int>> queries(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  vector<bool> ans = checkIfPrerequisite(n, prerequisites, queries);

  for (bool x: ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main()
{
  solution();

  return 0;
}
