/**
 * 1. Heap - O(nlogn)
 *      Maintain heap of number and frequency pair
 *      Remove numbers with lowest frequency till allowed
 *        Remove whole number rather than one by one based on frequency and allowed removals
 *      Answer if size of heap in end
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

struct MinFreqPqComparator {
  bool operator()(pp first, pp second) {
    return first.second > second.second;
  }
};

int findLeastNumOfUniqueInts(vector<int>& arr, int k)
{
  int n = arr.size();

  unordered_map<int, int> freqMap;
  for (int x: arr) {
    freqMap[x]++;
  }

  priority_queue<pp, vector<pp>, MinFreqPqComparator> minFreqPq;

  for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
    minFreqPq.push(*it);
  }

  while (!minFreqPq.empty()) {
    int topFreq = minFreqPq.top().second;

    if (topFreq > k) {
      break;
    }

    k -= topFreq;
    minFreqPq.pop();
  }

  return minFreqPq.size();
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << findLeastNumOfUniqueInts(arr, k) << endl;
}

int main()
{
  solution();

  return 0;
}
