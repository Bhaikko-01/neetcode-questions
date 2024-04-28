/**
 * 1. Insert and run merge() - O(n)
 *      Find index, where to insert the interval by comparing start of currInterval and newInterval
 *        Check if end are equal,
 *          merge by smaller end
 *        Else check if start is less of newInterval
 *          If yes, merge at that index
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
  int n = intervals.size();

  vector<vector<int>> ans;

  ans.push_back(intervals[0]);

  for (int i = 1; i < n; i++) {
    vector<int> lastVector = ans.back();

    if (intervals[i][0] <= lastVector[1]) {
      lastVector[1] = max(intervals[i][1], lastVector[1]);
      ans.pop_back();
      ans.push_back(lastVector);
    } else {
      ans.push_back(intervals[i]);
    }
  }

  return ans;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
  int n = intervals.size();

  int indexToMerge = -1;
  for (int i = 0; i < n; i++) {
    if (newInterval[0] == intervals[i][0]) {
      if (newInterval[1] < intervals[i][1]) {
        indexToMerge = i;
        break;
      }
    }

    if (newInterval[0] < intervals[i][0]) {
      indexToMerge = i;
      break;
    }
  }

  if (indexToMerge == -1) {
    intervals.push_back(newInterval);
  } else {
    intervals.insert(intervals.begin() + indexToMerge, newInterval);

  }

  return merge(intervals);
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> intervals(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> intervals[i][0] >> intervals[i][1];
  }

  vector<int> newInterval(2);
  cin >> newInterval[0] >> newInterval[1];

  vector<vector<int>> ans = insert(intervals, newInterval);

  cout << "----" << endl;

  for (auto x: ans) {
    for (int y: x) {
      cout << y << " ";
    }
    cout << endl;
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
