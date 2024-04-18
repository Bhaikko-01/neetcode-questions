/**
 * 1. Calculate Distance, store and store - O(nlogn) [T], O(n) [S]
 *      Calculate distance of each coordinate from origin
 *      Sort in ascending order by distance
 *      Return k first elements
 * 2. Heap - O(n) + O(klogn) [T], O(n) [S]
 *      Creating heap of elements having distance using heapify should take O(n) time
 *      Pop k elements and push to ans array - O(klogn)
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<vector<int>, double> coorDistancePair;

// ! 1.
vector<vector<int>> kClosestSort(vector<vector<int>>& points, int k)
{
  int n = points.size();

  vector<coorDistancePair> pairs;
  for (vector<int> coord: points) {
    double distance = sqrt(coord[0] * coord[0] + coord[1] * coord[1]);

    coorDistancePair pair(coord, distance);
    pairs.push_back(pair);
  }

  sort(pairs.begin(), pairs.end(), [](coorDistancePair a, coorDistancePair b) -> bool {
    return a.second < b.second;
  });

  vector<vector<int>> ans;
  for (int i = 0; i < k; i++) {
    ans.push_back(pairs[i].first);
  }

  return ans;
}

struct MinDistanceHeapComparator {
  bool operator()(coorDistancePair a, coorDistancePair b) const {
    return a.second > b.second;
  }
};

// ! 2.
vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
  int n = points.size();

  vector<coorDistancePair> pairs;
  for (vector<int> coord: points) {
    double distance = sqrt(coord[0] * coord[0] + coord[1] * coord[1]);

    coorDistancePair pair(coord, distance);
    pairs.push_back(pair);
  }

  priority_queue<coorDistancePair, vector<coorDistancePair>, MinDistanceHeapComparator> minHeap(pairs.begin(), pairs.end());

  vector<vector<int>> ans;
  for (int i = 0; i < k; i++) {
    ans.push_back(minHeap.top().first);

    minHeap.pop();
  }

  return ans;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<vector<int>> points(n);

  for (int i = 0; i < n; i++) {
    vector<int> point(2);
    cin >> point[0] >> point[1];

    points[i] = point;
  }

  vector<vector<int>> ans = kClosest(points, k);

  for (vector<int> coord: ans) {
    cout << coord[0] << " " << coord[1] << endl;
  }
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
