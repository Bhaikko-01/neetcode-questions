#include <bits/stdc++.h>

using namespace std;

vector<int> getDistances(vector<int>& edges, int node)
{
  int n = edges.size();

  vector<int> distances(n, -1);
  distances[node] = 0;

  int currNode = edges[node];
  int distance = 1;

  while (currNode != -1 && distances[currNode] == -1) {
    distances[currNode] = distance;

    currNode = edges[currNode];
    distance++;
  }

  return distances;
}

int closestMeetingNode(vector<int>& edges, int node1, int node2)
{
  int n = edges.size();

  vector<int> node1Distances = getDistances(edges, node1);
  vector<int> node2Distances = getDistances(edges, node2);

  int minDis = INT_MAX;
  int ans = -1;

  for (int x: node1Distances) {
    cout << x << " ";
  }
  cout << endl;
  for (int x: node2Distances) {
    cout << x << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    int dis1 = node1Distances[i];
    int dis2 = node2Distances[i];

    if (dis1 != -1 && dis2 != -1) {
      int currDis = max(dis1, dis2);

      if (currDis < minDis) {
        ans = i;
        minDis = currDis;
      } else if (currDis == minDis) {
        if (ans == -1) {
          ans = i;
        } else {
          ans = min(i, ans);
        }
      }
    }
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> edges(n);
  for (int i = 0; i < n; i++) {
    cin >> edges[i];
  }

  int node1, node2;
  cin >> node1 >> node2;

  cout << closestMeetingNode(edges, node1, node2) << endl;
}

int main()
{
  solution();

  return 0;
}
