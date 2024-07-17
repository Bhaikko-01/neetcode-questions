/**
 * 1. Priority Queue
 *      Similar to reorganize-string
 *      Maintain lastUsed element and check if that element was used for 2 times
 *      If 2 times used then only push to queue
 *      Otherwise keep that in maxHeap for further processing
 *      Other flow remains same as reorganize
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> pp;

struct MaxHeapComparator {
  bool operator()(pp first, pp second) {
    return first.second <= second.second;
  }
};

string longestDiverseString(int a, int b, int c)
{
  priority_queue<pp, vector<pp>, MaxHeapComparator> maxHeapOccurence;

  if (a > 0) {
    maxHeapOccurence.push({ 'a', a });
  }

  if (b > 0) {
    maxHeapOccurence.push({ 'b', b });
  }

  if (c > 0) {
    maxHeapOccurence.push({ 'c', c });
  }

  queue<pp> pending;

  string ans = "";
  pp lastUsed = { ' ', 0 };

  while (!maxHeapOccurence.empty()) {
    pp top = maxHeapOccurence.top();
    maxHeapOccurence.pop();

    ans += top.first;
    top.second--;

    if (lastUsed.first == top.first) {
      if (lastUsed.second == 1) {
        if (top.second >= 1) {
          pending.push(top);
        }
      } else {
        lastUsed.second++;
        maxHeapOccurence.push(top);
      }
    } else {
      lastUsed = { top.first, 1 };

      if (top.second >= 1) {
        maxHeapOccurence.push(top);
      }
    }

    if (!pending.empty()) {
      pp front = pending.front();

      if (front.first != top.first) {
        maxHeapOccurence.push(front);
        pending.pop();
      }
    }
  }

  return ans;
}

void solution()
{
  int a, b, c;
  cin >> a >> b >> c;

  cout << longestDiverseString(a, b, c) << endl;
}

int main()
{
  solution();

  return 0;
}
