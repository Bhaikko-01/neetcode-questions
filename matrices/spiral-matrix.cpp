#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();

  int count = m * n;

  vector<int> ans(count);
  int index = 0;

  int leftLimit = 0, rightLimit = m - 1,
      topLimit = 0, bottomLimit = n - 1;

  while (true) {
    for (int i = leftLimit; i <= rightLimit; i++) {
      ans[index++] = matrix[topLimit][i];
    }
    topLimit++;

    if (index >= count) { break; }

    for (int i = topLimit; i <= bottomLimit; i++) {
      ans[index++] = matrix[i][rightLimit];
    }
    rightLimit--;

    if (index >= count) { break; }

    for (int i = rightLimit; i >= leftLimit; i--) {
      ans[index++] = matrix[bottomLimit][i];
    }
    bottomLimit--;

    if (index >= count) { break; }

    for (int i = bottomLimit; i >= topLimit; i--) {
      ans[index++] = matrix[i][leftLimit];
    }
    leftLimit++;

    if (index >= count) { break; }
  }

  return ans;
}

void solution()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  vector<int> ans = spiralOrder(matrix);

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
