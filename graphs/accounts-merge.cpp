/**
 * 1. DFS
 *      Create graph of emails with adjacent emails having edges
 *        No need to create graph of N^2 edges as one node is connected to another due to transitivity
 *      Maintain emailNameMapping for reverse lookup
 *      Run DFS on each starting email and all emails it visit belong to same person
 *        Once DFS is over, current visited emails are grouped together
 *          even if name repeats itself
 */

#include <bits/stdc++.h>

using namespace std;

void dfs(
  unordered_map<string, unordered_map<string, bool>>& graph,
  string curr,
  set<string>& mergedAccounts,
  unordered_map<string, bool>& visited
) {
  if (visited[curr]) {
    return;
  }

  visited[curr] = true;

  mergedAccounts.insert(curr);

  for (auto it = graph[curr].begin(); it != graph[curr].end(); it++) {
    if (!visited[it->first]) {
      dfs(graph, it->first, mergedAccounts, visited);
    }
  }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
  int n = accounts.size();

  unordered_map<string, unordered_map<string, bool>> graph;
  unordered_map<string, string> emailNameMapping;

  for (vector<string> account: accounts) {
    string name = account[0];

    int m = account.size();

    if (m == 2) {
      graph[account[1]] = unordered_map<string, bool>();
      emailNameMapping[account[1]] = name;
    }

    for (int i = 1; i < m - 1; i++) {
      string curr = account[i];
      string next = account[i + 1];

      graph[curr][next] = true;
      graph[next][curr] = true;

      emailNameMapping[curr] = name;
      emailNameMapping[next] = name;
    }
  }

  unordered_map<string, bool> visited;
  vector<vector<string>> ans;

  int count = 1;
  for (auto it = graph.begin(); it != graph.end(); it++) {
    if (!visited[it->first]) {
      set<string> mergedAccounts;
      dfs(graph, it->first, mergedAccounts, visited);

      vector<string> curr(1, emailNameMapping[it->first]);
      for (auto x = mergedAccounts.begin(); x != mergedAccounts.end(); x++) {
        curr.push_back(*x);
      }
      ans.push_back(curr);
    }
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<string>> accounts(n);

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;

    accounts[i] = vector<string>(m);

    for (int j = 0; j < m; j++) {
      cin >> accounts[i][j];
    }
  }

  auto ans = accountsMerge(accounts);

  for (auto x: ans) {
    for (auto y: x) {
      cout << y << " ";
    }
    cout << endl;
  }
}

/**
 *
4
3 John johnsmith@mail.com john_newyork@mail.com
3 John johnsmith@mail.com john00@mail.com
2 Mary mary@mail.com
2 John johnnybravo@mail.com
 */

int main()
{
  solution();

  return 0;
}
