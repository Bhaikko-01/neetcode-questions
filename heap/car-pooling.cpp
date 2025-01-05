/**
 * 1. Heap and Time scheduling - O(nlogn)
 *      Create minHeaps for startTime and endTime
 *      Pick time from both and process the smaller time as that will occur first
 *        if startTime is processed, increase capacity
 *        if endTime is process, decrease capacity
 *      Process times till startHeap isnt empty since endHeap will always end after startHeap
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

struct PairGreater {
  bool operator()(pp first, pp second) {
    return first.second >= second.second;
  }
};

bool carPooling(vector<vector<int>>& trips, int capacity)
{
  priority_queue<pp, vector<pp>, PairGreater> startCapacityMinHeap;
  priority_queue<pp, vector<pp>, PairGreater> endCapacityMinHeap;

  int n = trips.size();

  for (int i = 0; i < n; i++) {
    startCapacityMinHeap.push({ trips[i][0], trips[i][1] });
    endCapacityMinHeap.push({ trips[i][0], trips[i][2] });
  }

  int currCapacity = 0;

  while (!startCapacityMinHeap.empty()) {
    pp startTimePair = startCapacityMinHeap.top();
    pp endTimePair = endCapacityMinHeap.top();

    if (startTimePair.second < endTimePair.second) {
      currCapacity += startTimePair.first;
      startCapacityMinHeap.pop();
    } else {
      currCapacity -= endTimePair.first;
      endCapacityMinHeap.pop();
    }

    if (currCapacity > capacity) {
      return false;
    }
  }

  return true;
}

void solution()
{
  int n, capacity;
  cin >> n >> capacity;

  vector<vector<int>> trips(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> trips[i][0] >> trips[i][1] >> trips[i][2];
  }

  cout << carPooling(trips, capacity) << endl;
}

int main()
{
  solution();

  return 0;
}
