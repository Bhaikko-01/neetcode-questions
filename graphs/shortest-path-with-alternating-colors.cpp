/**
 * 1. BFS - O(n + m)
 *      BFS is used as shortest path is required and all edge have same weight
 *      Convert edges into adjacency list and run BFS twice
 *        - first starting with RedAllowed
 *        - second starting with Red Not allowed
 *      A node is marked visited based on coming from an edge so two visited array are maintained
 */

#include <bits/stdc++.h>

using namespace std;

// * red -> true, blue -> false
using pp = pair<int, bool>;

vector<int> getAnswerWithBfs(
  vector<vector<pp>>& graph,
  bool redAllowed,
  int n
) {
  vector<int> answer(n, INT_MAX);
  vector<bool> redVisited(n, false);
  vector<bool> blueVisited(n, false);

  queue<pp> pending;
  pending.push({0, !redAllowed});
  answer[0] = 0;

  redVisited[0] = !redAllowed;
  blueVisited[0] = redAllowed;

  int currDistance = 0;

  while (!pending.empty()) {
    int currNodesCount = pending.size();

    for (int i = 0; i < currNodesCount; i++) {
      int currNode = pending.front().first;
      pending.pop();

      answer[currNode] = min(currDistance, answer[currNode]);

      for (pp& neighbor: graph[currNode]) {
        if (redAllowed) {
          if (!redVisited[neighbor.first] && neighbor.second == true) {
            pending.push(neighbor);
            redVisited[neighbor.first] = true;
          }
        } else {
          if (!blueVisited[neighbor.first] && neighbor.second == false) {
            pending.push(neighbor);
            blueVisited[neighbor.first] = true;
          }
        }
      }

    }

    redAllowed = !redAllowed;
    currDistance++;
  }

  return answer;
}

vector<int> shortestAlternatingPaths(
  int n,
  vector<vector<int>>& redEdges,
  vector<vector<int>>& blueEdges
) {
  vector<vector<pp>> graph(n, vector<pp>());

  for (vector<int>& redEdge: redEdges) {
    graph[redEdge[0]].push_back({redEdge[1], true});
  }

  for (vector<int>& blueEdge: blueEdges) {
    graph[blueEdge[0]].push_back({blueEdge[1], false});
  }

  vector<int> startWithReds = getAnswerWithBfs(graph, true, n);
  vector<int> startWithBlues = getAnswerWithBfs(graph, false, n);
  vector<int> answer(n);

  for (int i = 0; i < n; i++) {
    answer[i] = min(startWithBlues[i], startWithReds[i]);

    // cout << i << " " << startWithReds[i] << " " << startWithBlues[i] << endl;

    if (answer[i] == INT_MAX) {
      answer[i] = -1;
    }
  }

  return answer;
}

void solution()
{
  int n;
  cin >> n;

  int rn;
  cin >> rn;

  vector<vector<int>> redEdges(rn, vector<int>(2));
  for (int i = 0; i < rn; i++) {
    cin >> redEdges[i][0] >> redEdges[i][1];
  }

  int bn;
  cin >> bn;

  vector<vector<int>> blueEdges(bn, vector<int>(2));
  for (int i = 0; i < bn; i++) {
    cin >> blueEdges[i][0] >> blueEdges[i][1];
  }

  vector<int> answer = shortestAlternatingPaths(n, redEdges, blueEdges);

  for (int x: answer) {
    cout << x << " ";
  }

  cout << endl;
}

int main()
{
  solution();

  return 0;
}
