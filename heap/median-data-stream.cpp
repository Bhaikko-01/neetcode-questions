/**
 * 1. Brute force - O(mnlogn)
 *      Copy array and sort to find mid elements
 * 2. Heap O(nlogn)
 *      Maintain two heaps with equal sizes
 *        maxHeap containing elements less than median
 *        minHeap containing elements more than median
 *        This is done so than, we these two heaps are combined, they would sorted array and
 *          would have equal elements.
 *        The heaps would contain two halves of equal size.
 *          For odd elements, assume minHeapMaxElements will have median so it will have (n/2+1) size
 *      If num is inserted,
 *        if it is less than top of minHeapMaxElements, then it should to maxHeapMinElements
 *          else move to minHeapMaxElements
 *          This is to send element to correct half based on mid values of heaps
 *        Reshuffle heaps based on size,
 *          if n is odd, one heap will have one more element than other. (minHeapMaxElements in our case)
 *          if n is even, both heap will have same number of elements
 *          if above size not met, reshuffle,
 *            remove from heap with more elements and push to lesser heap
 *      For median
 *        if n is odd, minHeapMaxElement.top
 *        else (min.top() + max.top()) / 2
*/

#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
private:
  priority_queue<int> maxHeapElementsLessThanMedian;
  priority_queue<int, vector<int>, greater<int>> minHeapElementsMoreThanMedian;
  int n;
private:
  bool areHeapsBalanced()
  {
    int sizeByTwo = n / 2;

    if (n & 1) {
      return maxHeapElementsLessThanMedian.size() == sizeByTwo &&
             minHeapElementsMoreThanMedian.size() == sizeByTwo + 1;
    } else {
      return maxHeapElementsLessThanMedian.size() == sizeByTwo &&
             minHeapElementsMoreThanMedian.size() == sizeByTwo;
    }
  }
public:
  MedianFinder() {
    this->n = 0;
  }

  void addNum(int num) {
    n++;

    if (minHeapElementsMoreThanMedian.size() == 0) {
      minHeapElementsMoreThanMedian.push(num);
    } else {
      if (minHeapElementsMoreThanMedian.top() > num) {
        maxHeapElementsLessThanMedian.push(num);
      } else {
        minHeapElementsMoreThanMedian.push(num);
      }
    }

    if (!areHeapsBalanced()) {
      if (maxHeapElementsLessThanMedian.size() > minHeapElementsMoreThanMedian.size()) {
        minHeapElementsMoreThanMedian.push(maxHeapElementsLessThanMedian.top());
        maxHeapElementsLessThanMedian.pop();
      } else {
        maxHeapElementsLessThanMedian.push(minHeapElementsMoreThanMedian.top());
        minHeapElementsMoreThanMedian.pop();
      }
    }
  }

  double findMedian() {
    if (n & 1) {
      return minHeapElementsMoreThanMedian.top();
    } else {
      return (maxHeapElementsLessThanMedian.top() + minHeapElementsMoreThanMedian.top()) * 0.5;
    }
  }
};

void solution()
{
  // MedianFinder medianFinder;
  // medianFinder.addNum(1);    // arr = [1]
  // medianFinder.addNum(2);    // arr = [1, 2]
  // cout << medianFinder.findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
  // medianFinder.addNum(3);    // arr[1, 2, 3]
  // cout << medianFinder.findMedian() << endl; // return 2.0

  MedianFinder medianFinder;
  medianFinder.addNum(-1);    // arr = [1]
  cout << medianFinder.findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
  medianFinder.addNum(-2);    // arr = [1, 2]
  cout << medianFinder.findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
  medianFinder.addNum(-3);    // arr[1, 2, 3]
  cout << medianFinder.findMedian() << endl; // return 2.0
  medianFinder.addNum(-4);    // arr[1, 2, 3]
  cout << medianFinder.findMedian() << endl; // return 2.0
  medianFinder.addNum(-5);    // arr[1, 2, 3]
  cout << medianFinder.findMedian() << endl; // return 2.0
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
