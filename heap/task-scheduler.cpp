/**
 * Note: Pick the task with max occurence with valid config
 *  Valid config is
 *    Executable in currCycle based on last executed Time
 *    Already not executed by index
 * Max occurence is picked because it will be available quickest in future and less change of CPU idleness
 * 1. Brute Force - O(size * n * 26), size is number of tasks, n is cycle per task.
 *      Polling out task queue if a task can be executed
 *      Pick max occuring element iteratively
 *        Task will be picked by checking in 'A' to 'Z' not using array index
 *          therefore, it will take O(26)
 *      Process the task by
 *        marking last execution time
 *        marking executed for that index
 *      Keep track of tasks executed number to end loop
 * 2. Heap and Queue - O(n * 26)
 *      While heap or queue are non-empty, of size 26 as 'A' <= Task <= 'Z'
 *      Store occurence in maxheap of tasks to track which are pending
 *        Process task by
 *          decreasing occurence and storing in queue the next cycle it will be availble
 *          queue.push({ occurence - 1, currCycles + n })
 *      Check queue top if it is available for processing by comparing nextAvailableTime and currCycles
 *        If avaialble, push to maxHeap and pop from queue
 *      increase currCycles with every iteration
 *      Using queue as the element first processed will be first available as all tasks take
 *        equal number of time for execution
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1.
int leastIntervalBrute(vector<char>& tasks, int n)
{
  int size = tasks.size();

  unordered_map<char, int> occurence;
  unordered_map<char, int> lastExecutedAt;

  int currCycle = 0;
  int tasksExecuted = 0;

  for (char a: tasks) {
    occurence[a]++;
  }

  while (tasksExecuted != size) {
    currCycle++;

    int maxOccurence = INT_MIN;
    char currTask = '-';

    // ! O(1) work
    for (int i = 'A'; i <= 'Z'; i++) {
      if (occurence[i] > 0) {
        if (lastExecutedAt.find(i) == lastExecutedAt.end() || currCycle - lastExecutedAt[i] > n) {
          if (maxOccurence < occurence[i]) {
            maxOccurence = occurence[i];
            currTask = i;
          }
        }
      }
    }

    if (currTask == '-') {
      continue;
    }

    lastExecutedAt[currTask] = currCycle;
    occurence[currTask]--;
    tasksExecuted++;
  }

  return currCycle;
}

// ! 2.
int leastInterval(vector<char>& tasks, int n)
{
  int size = tasks.size();
  int currCycles = 0;

  int tasksExecuted = 0;

  unordered_map<char, int> occurence;
  priority_queue<int> maxHeapForOccurence;
  queue<pair<int, int>> coolingTasks;

  for (char x: tasks) {
    occurence[x]++;
  }

  for (char x = 'A'; x <= 'Z'; x++) {
    if (occurence[x]) {
      maxHeapForOccurence.push(occurence[x]);
    }
  }

  while (maxHeapForOccurence.size() || coolingTasks.size()) {
    currCycles++;

    if (maxHeapForOccurence.size() != 0) {
      int currTask = maxHeapForOccurence.top();
      maxHeapForOccurence.pop();

      if (currTask - 1 > 0) {
        coolingTasks.push({ currTask - 1, currCycles + n });
      }
    }

    if (coolingTasks.size() != 0) {
      pair<int, int> coolingTask = coolingTasks.front();

      if (currCycles == coolingTask.second) {
        maxHeapForOccurence.push(coolingTask.first);
        coolingTasks.pop();
      }
    }
  }

  return currCycles;
}

void solution()
{
  int size, n;
  cin >> size >> n;

  vector<char> tasks(size);
  for (int i = 0; i < size; i++) {
    cin >> tasks[i];
  }

  cout << leastInterval(tasks, n) << endl;
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
