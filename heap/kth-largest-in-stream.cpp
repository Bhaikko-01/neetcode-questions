/**
 * m - number of operations, n - length of initial array
 * 1. Sort and return kth element - O(mnlogn)
 *      Sort array and return kth largest
 *      Insert element at end and sort again, return kth largest
 * 2. Insert using Binary Search - O(nlogn + logn + m) [T]
 *      Sort initially - O(nlogn)
 *      Find position to insert element - O(logn)
 *      Insert element at correct position and return - O(n)
 * 3. Min heap of k elements - O(n + nlogn)
 *      create heap of initial elements - O(n)
 *      remove elements to make it k size which in worst case could be n - O(nlogn)
 *      Top element will be kth largest - O(1)
 *      pop and push new elements based on top of min heap - O(logn)
 *      K size is maintained as we never remove elements from array
 *        so if element is less than kth largest, it can never be kth largest in future
*/

#include <bits/stdc++.h>

using namespace std;

struct GreaterInt {
  bool operator()(int a, int b) const {
    // The element for which this is true is pushed down the heap
    return a > b;
  }
};

class KthLargest {
private:
  priority_queue<int, vector<int>, GreaterInt> minHeap;
  int k;

public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;

    // Heapify - O(n)
    minHeap = priority_queue<int, vector<int>, GreaterInt>(nums.begin(), nums.end());

    while (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  int add(int val) {
    if (minHeap.size() < k) {
      minHeap.push(val);
    } else {
      if (minHeap.top() < val) {
        minHeap.pop();
        minHeap.push(val);
      }
    }

    return minHeap.top();
  }
};

void solution()
{
  // vector<int> nums = { 0 };
  // KthLargest kthLargest = KthLargest(2, nums);
  // cout << kthLargest.add(-1) << endl;
  // cout << kthLargest.add(1) << endl;
  // cout << kthLargest.add(-2) << endl;
  // cout << kthLargest.add(-4) << endl;
  // cout << kthLargest.add(3) << endl;

  vector<int> nums = { 4, 5, 8, 2 };
  KthLargest kthLargest = KthLargest(3, nums);
  cout << kthLargest.add(3) << endl;   // return 4
  cout << kthLargest.add(5) << endl;   // return 5
  cout << kthLargest.add(10) << endl;  // return 5
  cout << kthLargest.add(9) << endl;   // return 8
  cout << kthLargest.add(4) << endl;

  // vector<int> nums;
  // KthLargest kthLargest = KthLargest(1, nums);
  // cout << kthLargest.add(-3) << endl;   // return 4
  // cout << kthLargest.add(-2) << endl;   // return 5
  // cout << kthLargest.add(-4) << endl;  // return 5
  // cout << kthLargest.add(0) << endl;   // return 8
  // cout << kthLargest.add(4) << endl;
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
