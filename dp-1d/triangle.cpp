#include <bits/stdc++.h>

using namespace std;

string getKey(int a, int b)
{
  return to_string(a) + "," + to_string(b);
}

int minimumTotal(vector<vector<int>>& triangle, int level, int index, unordered_map<string, int>& occured)
{
  int n = triangle.size();
  string key = getKey(level, index);

  if (level >= n) {
    return 0;
  }

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  int leftPathSum = minimumTotal(triangle, level + 1, index, occured);
  int rightPathSum = minimumTotal(triangle, level + 1, index + 1, occured);

  occured[key] = min(leftPathSum, rightPathSum) + triangle[level][index];
  return occured[key];
}

int minimumTotalMemo(vector<vector<int>>& triangle)
{
  unordered_map<string, int> occured;

  return minimumTotal(triangle, 0, 0, occured);
}

int minimumTotal(vector<vector<int>>& triangle)
{
  int n = triangle.size();

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i + 1; j++) {
      int leftPathSum = dp[i + 1][j];
      int rightPathSum = dp[i + 1][j + 1];

      dp[i][j] = min(leftPathSum, rightPathSum) + triangle[i][j];
    }
  }

  return dp[0][0];
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> triangle(n);

  for (int i = 0; i < n; i++) {
    triangle[i] = vector<int>(i + 1);

    for (int j = 0; j < i + 1; j++) {
      cin >> triangle[i][j];
    }
  }

  cout << minimumTotal(triangle) << endl;
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
