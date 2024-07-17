/**
 * 1. Priority Queue
 *      Maintain occurence of each char and create maxHeap based on it
 *      Select elements with highest occurence to place in ans string
 *      Push the currUsedEle in queue if count more than 0 and
 *        pop from queue if currUsedEl is not same as queue front
 *      If queue front and currUsedEle top are same and no elements in maxHeap then no ans possible
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> pp;

struct PairComparator {
  bool operator()(pp first, pp second) {
    return first.second <= second.second;
  }
};

string reorganizeString(string s)
{
  int n = s.size();

  unordered_map<char, int> occurence;
  for (char x: s) {
    occurence[x]++;
  }

  priority_queue<pp, vector<pp>, PairComparator> maxHeapOfOccurence;
  queue<pp> pending;
  for (auto it: occurence) {
    maxHeapOfOccurence.push({ it.first, it.second });
  }

  string ans = "";
  bool firstEl = true;

  while (!maxHeapOfOccurence.empty() || !pending.empty()) {
    pp top = maxHeapOfOccurence.top();
    maxHeapOfOccurence.pop();

    ans += top.first;
    top.second--;

    if (top.second > 0) {
      pending.push(top);
    }

    if (!pending.empty()) {
      pp front = pending.front();

      if (front.first == top.first) {
        if (maxHeapOfOccurence.empty()) {
          return "";
        }
      } else {
        maxHeapOfOccurence.push(front);
        pending.pop();
      }
    }
  }

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  cout << reorganizeString(s) << endl;
}

int main()
{
  solution();

  return 0;
}
