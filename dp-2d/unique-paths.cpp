#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int i, int j, int parentX, int parentY, int m, int n)
{
  if (i == m - 1 && j == n - 1) {
    return 1;
  }

  if (i < 0 || j < 0 || i >= m || j >= n) {
    return 0;
  }

  int totalPaths = 0;
  if (i - 1 != parentX) {
    totalPaths += uniquePaths(i - 1, j, i, j, m, n);
  }

  if (i + 1 != parentX) {
    totalPaths += uniquePaths(i + 1, j, i, j, m, n);
  }

  if (j - 1 != parentY) {
    totalPaths += uniquePaths(i, j - 1, i, j, m, n);
  }

  if (j + 1 != parentY) {
    totalPaths += uniquePaths(i, j + 1, i, j, m, n);
  }

  return totalPaths;
}

int uniquePaths(int m, int n)
{

}

void solution()
{
  int m, n;
  cin >> m >> n;


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
