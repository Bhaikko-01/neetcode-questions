/**
 * MIGHT WANNA COME BACK TO THIS ONCE
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> pp;

string generateTicketKey(string ticket1, string ticket2) {
  return ticket1 + "," + ticket2;
}

void dfs(unordered_map<string, vector<string>>& graph, string curr, string parent, unordered_map<string, bool>& edgeTraversed,vector<string>& ans)
{
  if (edgeTraversed[generateTicketKey(parent, curr)]) {
    return;
  }

  edgeTraversed[generateTicketKey(parent, curr)] = true;
  ans.push_back(curr);

  for (string neighbor: graph[curr]) {
    if (!edgeTraversed[generateTicketKey(curr, neighbor)]) {
      dfs(graph, neighbor, curr, edgeTraversed, ans);
    }
  }
}

vector<string> findItinerary(vector<vector<string>>& tickets)
{
  int n = tickets.size();

  unordered_map<string, vector<string>> graph;
  unordered_map<string, bool> edgeTraversed;

  for (vector<string> ticket: tickets) {
    graph[ticket[0]].push_back(ticket[1]);
  }

  for (unordered_map<string, vector<string>>::iterator it = graph.begin(); it != graph.end(); it++) {
    sort(it->second.begin(), it->second.end());
  }

  string start = "JFK";

  vector<string> ans;

  dfs(graph, start, "-", edgeTraversed, ans);

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<string>> tickets(n, vector<string>(2));
  for (int i = 0; i < n; i++) {
    cin >> tickets[i][0] >> tickets[i][1];
  }

  vector<string> ans = findItinerary(tickets);
  for (string x: ans) {
    cout << x << " ";
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
