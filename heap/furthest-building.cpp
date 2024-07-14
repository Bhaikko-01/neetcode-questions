/**
 * 1. Greedy Heap - O(nlogn)
 *      Get diff of height at each index
 *        If diff is negative then can cross
 *        If diff is positive
 *          try to satisfy diff with bricks. If not satisfiable
 *          Use ladder with diff with highest value and update bricks
 *          Pop max diff from heap as in future, that diff can never be satisfied with bricks
 */

#include <bits/stdc++.h>

using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders)
{
  int n = heights.size();

  priority_queue<int> differenceMaxHeap;

  for (int i = 0; i < n - 1; i++) {
    int diff = heights[i + 1] - heights[i];

    if (diff <= 0) {
      continue;
    }

    bricks -= diff;
    differenceMaxHeap.push(diff);

    if (bricks < 0) {
      if (ladders == 0) {
        return i;
      }

      ladders--;

      bricks += differenceMaxHeap.top();
      differenceMaxHeap.pop();
    }
  }

  return n - 1;
}

void solution()
{
  int n, bricks, ladders;
  cin >> n >> bricks >> ladders;

  vector<int> heights(n);

  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  cout << furthestBuilding(heights, bricks, ladders) << endl;
}

int main()
{
  solution();

  return 0;
}
