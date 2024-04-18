/**
 * 1. Brute Force - O(n^2)
 *      Find max and second max stones iteratively
 *      Remove them from array and perform stone value update
 *      Add new value to end
 * 2. Heap - O(nlogn)
 *      Maintain max heap of stone weights
 *      Pop two elements, perform stone value update and push to heap
 *      Do this till heap value is more than 1
*/

#include <bits/stdc++.h>

using namespace std;

struct GreaterInt {
  bool operator()(int a, int b) const {
    // If b is greater than it will go down the heap
    return b > a;
  }
};

int lastStoneWeight(vector<int>& stones)
{
  priority_queue<int, vector<int>, GreaterInt> stonesMaxHeap(stones.begin(), stones.end());

  while (stonesMaxHeap.size() > 1) {
    int firstStone = stonesMaxHeap.top();
    stonesMaxHeap.pop();

    int secondStone = stonesMaxHeap.top();
    stonesMaxHeap.pop();

    if (firstStone != secondStone) {
      stonesMaxHeap.push(abs(firstStone - secondStone));
    }
  }

  return stonesMaxHeap.size() > 0 ? stonesMaxHeap.top() : 0;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> stones(n);
  for (int i = 0; i < n; i++) {
    cin >> stones[i];
  }

  cout << lastStoneWeight(stones) << endl;
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
