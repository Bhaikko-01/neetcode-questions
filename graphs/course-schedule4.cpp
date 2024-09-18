/**
 * Graph is maintained such that if [a,b] exists,
 *  which means a is prerequisite of b then there is an edge from b to a
 *  meaning, for b, a must be finised first
 * 1. DFS for every query - O(q * (n + e))
 *      run DFS, if query[0] occurs when starting DFS from query[1] then
 *      query[0] must be finished before query[1]
 * 2. For every node, get all nodes possible to reach from that
 *    Then use that hashmap to ans queries
 *    DP can be used to populate hash-of-hashes
 */

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> dfs(vector<vector<int>>& graph, int curr, unordered_map<int, unordered_map<int, bool>>& reachable)
{
  if (reachable.find(curr) != reachable.end()) {
    return reachable[curr];
  }

  reachable[curr] = unordered_map<int, bool>();

  for (int neighbor: graph[curr]) {
    unordered_map<int, bool> neighborMapping = dfs(graph, neighbor, reachable);

    reachable[curr][neighbor] = true;

    for (auto x: neighborMapping) {
      reachable[curr][x.first] = true;
    }
  }

  return reachable[curr];
}

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
{
  vector<vector<int>> graph(numCourses, vector<int>());

  for (auto prerequisite: prerequisites) {
    graph[prerequisite[1]].push_back(prerequisite[0]);
  }

  unordered_map<int, unordered_map<int, bool>> reachable;

  for (int i = 0; i < numCourses; i++) {
    if (reachable.find(i) == reachable.end()) {
      dfs(graph, i, reachable);
    }
  }

  vector<bool> ans;

  for (vector<int> query: queries) {
    ans.push_back(reachable[query[1]][query[0]]);
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
