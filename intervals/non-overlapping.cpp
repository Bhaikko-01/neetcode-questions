/**
 * 1. Greedy - O(nlogn)
 *      Sort intervals by start and remove which overlap by comparing i.end and (i+1).start
 *      Maintain 'end' variable keeping track of current end
 *      If i.end < end, this means two intervals overlap
 *        remove the one which extends to farther as high chance of overlapping again
 *        end = min(i.end, end)
 *      Else keep the interval and update end by current end as no overlap exists
*/

#include <bits/stdc++.h>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
  int n = intervals.size();

  sort(intervals.begin(), intervals.end(), [](vector<int> first, vector<int> second) -> bool {
    if (first[0] == second[0]) {
      return first[1] < second[1];
    }

    return first[0] < second[0];
  });

  int currEnd = intervals[0][1];
  int count = 0;

  for (int i = 1; i < n; i++) {
    if (intervals[i][0] < currEnd) {
      count++;
      currEnd = min(intervals[i][1], currEnd);
    } else {
      currEnd = intervals[i][1];
    }
  }

  return count;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> intervals(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> intervals[i][0] >> intervals[i][1];
  }

  cout << eraseOverlapIntervals(intervals) << endl;
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
