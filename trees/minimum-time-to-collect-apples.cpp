#include <bits/stdc++.h>

using namespace std;

typedef pair<int, bool> pp;

pp minTime(unordered_map<int, vector<int>>& tree, vector<bool>& hasApple, int currNode, vector<bool>& visited)
{
  if (visited[currNode]) {
    return pp(0, false);
  }

  visited[currNode] = true;

  if (tree[currNode].size() == 0) {
    return pp(0, hasApple[currNode]);
  }

  pp currTime(0, hasApple[currNode]);

  for (int child: tree[currNode]) {
    pp childApplesTime = minTime(tree, hasApple, child, visited);

    if (childApplesTime.second) {
      currTime.first += childApplesTime.first + 2;

      currTime.second = true;
    }
  }

  return currTime;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
{
  unordered_map<int, vector<int>> tree;

  for (vector<int> edge : edges) {
    tree[edge[0]].push_back(edge[1]);
    tree[edge[1]].push_back(edge[0]);
  }

  vector<bool> visited(n, false);
  pp ans = minTime(tree, hasApple, 0, visited);

  return ans.first;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> edges(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  vector<bool> hasApple(n);
  for (int i = 0; i < n; i++) {
    bool el;
    cin >> el;
    hasApple[i] = el;
  }

  cout << minTime(n, edges, hasApple) << endl;
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
