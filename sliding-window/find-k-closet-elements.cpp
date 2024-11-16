/**
 * 1. MinHeap of differences - O(nlogn + klogn)
 *      Get differences of each element with x and push that element to heap along with diff
 *      Pick k elements from minHeap as top element will have least difference and will be closet
 * 2. Two pointer - O(logn) + O(k) + O(klogk)
 *      Find one element which is closet to target
 *      Use two pointers and move adjacent to original closet element as
 *        array is sorted, adjacent elements will be closet
 *      Pick k elements using two pointers
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

// ! 1.
struct GreaterPair {
  bool operator()(pp a, pp b) {
    if (a.second == b.second) {
      return a.first > b.first;
    }

    return a.second > b.second;
  }
};

// ! 1.
vector<int> findClosestElementsHeap(vector<int>& arr, int k, int x)
{
  int n = arr.size();

  vector<int> ans;

  priority_queue<pp, vector<pp>, GreaterPair> minPairHeap;

  for (int i = 0; i < n; i++) {
    int val = abs(arr[i] - x);

    minPairHeap.push({ arr[i], val });
  }

  for (int i = 0; i < k; i++) {
    pp currPair = minPairHeap.top();

    ans.push_back(currPair.first);

    minPairHeap.pop();
  }

  sort(ans.begin(), ans.end());

  return ans;
}

int binarySearch(vector<int>& arr, int tar)
{
  int l = 0,
      r = arr.size() - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (arr[mid] == tar) {
      return mid;
    }

    if (tar > arr[mid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  // * If 'tar' not found then this will point to index just less than tar
  // * 'tar' can be inserted just after this index
  return r;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
  int n = arr.size();

  int possibleTargetIndex = binarySearch(arr, x);

  int l = possibleTargetIndex,
      r = possibleTargetIndex + 1;

  vector<int> ans;

  while (k > 0) {
    if (l < 0) {
      ans.push_back(arr[r]);
      r++;
    } else if (r >= n) {
      ans.push_back(arr[l]);
      l--;
    } else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
      ans.push_back(arr[l]);
      l--;
    } else {
      ans.push_back(arr[r]);
      r++;
    }

    k--;
  }

  sort(ans.begin(), ans.end());

  return ans;
}

void solution()
{
  int n, k, x;
  cin >> n >> k >> x;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> ans = findClosestElements(arr, k, x);

  for (int x: ans) {
    cout << x << " ";
  }

  cout << endl;
}

int main()
{
  solution();

  return 0;
}
