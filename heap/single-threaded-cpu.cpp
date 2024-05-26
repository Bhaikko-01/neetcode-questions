#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Task {
  int index;
  ll arrivalTime;
  ll burstTime;
};

struct MinProcessingTimeComparator {
  bool operator()(Task& first, Task& second) {
    if (first.burstTime == second.burstTime) {
      return first.index > second.index;
    }

    return first.burstTime > second.burstTime;
  }
};

vector<int> getOrder(vector<vector<int>>& tasks)
{
  int n = tasks.size();

  vector<Task> tasksToRun(n);
  for (int i = 0; i < n; i++) {
    tasksToRun[i].index = i;
    tasksToRun[i].arrivalTime = tasks[i][0];
    tasksToRun[i].burstTime = tasks[i][1];
  }

  sort(tasksToRun.begin(), tasksToRun.end(), [](Task first, Task second) -> bool {
    return first.arrivalTime < second.arrivalTime;
  });

  priority_queue<Task, vector<Task>, MinProcessingTimeComparator> pendingTasks;

  int currIndex = 0;
  vector<int> order;
  ll currTime = 0;

  while (currIndex < n || !pendingTasks.empty()) {
    if (pendingTasks.empty()) {
      currTime = tasksToRun[currIndex].arrivalTime;
    } else {
      Task currTask = pendingTasks.top();
      pendingTasks.pop();

      order.push_back(currTask.index);

      currTime += currTask.burstTime;
    }

    while (true) {
      if (currIndex >= n) {
        break;
      }

      if (currTime >= tasksToRun[currIndex].arrivalTime) {
        pendingTasks.push(tasksToRun[currIndex]);

        currIndex++;
      } else {
        break;
      }
    }
  }

  return order;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> tasks(n, vector<int>(2));

  for (int i = 0; i < n; i++) {
    cin >> tasks[i][0] >> tasks[i][1];
  }

  vector<int> order = getOrder(tasks);

  for (int x: order) {
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
