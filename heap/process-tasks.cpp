#include <bits/stdc++.h>

using namespace std;

// first = index, second = value
typedef pair<int, int> pp;

struct MinHeapPair {
  bool operator()(pp& first, pp& second) {
    if (first.second == second.second) {
      return first.first > second.first;
    }

    return first.second > second.second;
  }
};

vector<int> assignTasks(vector<int>& servers, vector<int>& tasks)
{
  int n = servers.size(),
      m = tasks.size();

  priority_queue<pp, vector<pp>, MinHeapPair> availableServers, runningServers;

  vector<int> ans;

  for (int i = 0; i < n; i++) {
    availableServers.push({ i, servers[i] });
  }

  int taskIndex = 0;
  int currTime = 0;

  while (taskIndex < m) {
    if (availableServers.empty()) {
      pp server = runningServers.top();

      currTime = server.second;

      while (!runningServers.empty() && currTime == runningServers.top().second) {
        pp task = runningServers.top();
        runningServers.pop();

        availableServers.push({ task.first, servers[task.first] });
      }
    }

    while (true) {
      if (taskIndex >= m || availableServers.empty()) {
        break;
      }

      if (currTime >= taskIndex) {
        pp server = availableServers.top();
        availableServers.pop();

        ans.push_back(server.first);

        runningServers.push({ server.first, currTime + tasks[taskIndex] });

        taskIndex++;
      } else {
        break;
      }
    }

    currTime++;

    while (true) {
      if (runningServers.empty()) {
        break;
      }

      pp runningServer = runningServers.top();

      if (currTime >= runningServer.second) {
        availableServers.push({ runningServer.first, servers[runningServer.first] });
        runningServers.pop();
      } else {
        break;
      }
    }
  }

  return ans;
}

void solution()
{
  int n, m;
  cin >> n >> m;

  vector<int> servers(n),
              tasks(m);

  for (int i = 0; i < n; i++) {
    cin >> servers[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> tasks[i];
  }

  vector<int> ans = assignTasks(servers, tasks);

  for (int x: ans) {
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
