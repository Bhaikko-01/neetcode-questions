#include <bits/stdc++.h>

using namespace std;

int maxDistance(vector<vector<int>>& arrays)
{
  int m = arrays.size();

  int minOfAll = INT_MAX;
  int maxOfAll = INT_MIN;
  int minPickedIndex = -1;

  for (int i = 0; i < m; i++) {
    if (arrays[i][0] < minOfAll) {
      minOfAll = arrays[i][0];
      minPickedIndex = i;
    }
  }

  for (int i = 0; i < m; i++) {
    int n = arrays[i].size();

    if (i != minPickedIndex) {
      maxOfAll = max(maxOfAll, arrays[i][n - 1]);
    }
  }

  int ans1 = abs(maxOfAll - minOfAll);

  minOfAll = INT_MAX;
  maxOfAll = INT_MIN;
  int maxPickedIndex = -1;

  for (int i = 0; i < m; i++) {
    int n = arrays[i].size();

    if (arrays[i][n - 1] > maxOfAll) {
      maxOfAll = arrays[i][n - 1];
      maxPickedIndex = i;
    }
  }

  for (int i = 0; i < m; i++) {
    int n = arrays[i].size();

    if (i != maxPickedIndex) {
      minOfAll = min(minOfAll, arrays[i][0]);
    }
  }

  int ans2 = abs(maxOfAll - minOfAll);

  return max(ans1, ans2);
}

void solution()
{
  int m;
  cin >> m;

  vector<vector<int>> arrays(m);

  for (int i = 0; i < m; i++) {
    int n;
    cin >> n;

    arrays[i] = vector<int>(n);

    for (int j = 0; j < n; j++) {
      cin >> arrays[i][j];
    }
  }

  cout << maxDistance(arrays) << endl;
}

int main()
{
  solution();

  return 0;
}
