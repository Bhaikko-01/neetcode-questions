/**
 * 1. Dikjsktra - O((V + E)logV)
 *      - Probability is involved so vertexes are relaxed with the formula
 *          prob[v] = prob[u] * edgeProb(u, v)
 *      - Start node probability will be 1
 */

#include <bits/stdc++.h>

using namespace std;

using pp = pair<int, double>;

struct MaxProbabilityComparator {
  bool operator()(const pp& vertexA, const pp& vertexB) const {
    return vertexA.second < vertexB.second;
  }
};

double maxProbability(
  int n,
  vector<vector<int>>& edges,
  vector<double>& succProb,
  int start_node, int end_node
) {
  vector<vector<pp>> graph(n, vector<pp>());
  for (int i = 0; i < edges.size(); i++) {
    graph[edges[i][0]].push_back({ edges[i][1], succProb[i] });
    graph[edges[i][1]].push_back({ edges[i][0], succProb[i] });
  }

  priority_queue<pp, vector<pp>, MaxProbabilityComparator> pq;

  vector<int> isVisited(n, false);
  vector<double> probability(n, 0);

  pq.push({ start_node, 1 });
  probability[start_node] = 1;

  while (!pq.empty()) {
    pp currNode = pq.top();
    pq.pop();

    if (isVisited[currNode.first]) {
      continue;
    }

    isVisited[currNode.first] = true;

    if (currNode.first == end_node) {
      break;
    }

    for (pp& neighbor: graph[currNode.first]) {
      if (isVisited[neighbor.first]) {
        continue;
      }

      double neighborProb = probability[currNode.first] * neighbor.second;

      // cout << neighborProb << " " << probability[neighbor.first] << endl;

      if (neighborProb > probability[neighbor.first]) {
        probability[neighbor.first] = neighborProb;
        pq.push({ neighbor.first, neighborProb });
      }
    }
  }

  return probability[end_node];
}

void solution()
{
  int n;
  cin >> n;

  int m;
  cin >> m;

  vector<vector<int>> edges(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  cin >> m;
  vector<double> succProb(m);
  for (int i = 0; i < m; i++) {
    cin >> succProb[i];
  }

  int startNode, endNode;
  cin >> startNode >> endNode;

  cout << maxProbability(n, edges, succProb, startNode, endNode) << endl;
}

int main()
{
  solution();

  return 0;
}

/**
3
3
0 1
1 2
0 2
3
0.5 0.5 0.2
0 2
 */
