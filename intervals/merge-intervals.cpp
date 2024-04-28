/**
 * 1. Sort and merge - O(nlogn)
 *      Sort intervals by start and if they are same, sort by end
 *        This is done so we are sure start[i] < start[i+1] and we need to compare end[i] and start[i+1]
 *      Maintain another ans array and push first interval to that
 *      Merge into that interval till valid intervals possible
 *      Otherwise push current interval to ans
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
  int n = intervals.size();

  vector<vector<int>> ans;

  sort(intervals.begin(), intervals.end(), [](vector<int> first, vector<int> second) -> bool {
    if (first[0] == second[0]) {
      return first[1] < second[1];
    }

    return first[0] < second[0];
  });

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

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> intervals(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> intervals[i][0] >> intervals[i][1];
  }

  vector<vector<int>> ans = merge(intervals);

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
