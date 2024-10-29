#include <bits/stdc++.h>

using namespace std;

long long combinationOf2(int n)
{
  return ((long long)n * (n - 1)) / 2;
}

long long interchangeableRectangles(vector<vector<int>>& rectangles)
{
  int n = rectangles.size();

  unordered_map<double, int> ratioCount;

  for (int i = 0; i < n; i++) {
    double ratio = (double)rectangles[i][0] / rectangles[i][1];
    ratioCount[ratio]++;
  }

  long long ans = 0;

  for (auto it = ratioCount.begin(); it != ratioCount.end(); it++) {
    if (it->second >= 2) {
      ans += combinationOf2(it->second);
    }
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> rectangles(n, vector<int>(2));

  for (int i = 0; i < n; i++) {
    cin >> rectangles[i][0] >> rectangles[i][1];
  }

  cout << interchangeableRectangles(rectangles) << endl;
}

int main()
{
  solution();

  return 0;
}
