#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<vector<int>>& items, int query, vector<int>& runningMaxes)
{
  int n = items.size();

  int l = 0,
      r = n - 1;

  int ans = 0;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (items[mid][0] <= query) {
      ans = max(ans, runningMaxes[mid]);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return ans;
}

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
{
  int n = items.size();
  int m = queries.size();

  vector<int> ans;

  sort(items.begin(), items.end(), [](const vector<int>& first, const vector<int>& second) -> bool {
    if (first[0] == second[0]) {
      return first[1] < second[1];
    }

    return first[0] < second[0];
  });

  vector<int> runningMaxes(n);
  runningMaxes[0] = items[0][1];

  for (int i = 1; i < n; i++) {
    runningMaxes[i] = max(items[i][1], runningMaxes[i - 1]);
  }

  for (int query: queries) {
    ans.push_back(
      binarySearch(items, query, runningMaxes)
    );
  }

  return ans;
}

void solution()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> items(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> items[i][0] >> items[i][1];
  }

  vector<int> queries(m);
  for (int i = 0; i < m; i++) {
    cin >> queries[i];
  }

  vector<int> ans = maximumBeauty(items, queries);

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
