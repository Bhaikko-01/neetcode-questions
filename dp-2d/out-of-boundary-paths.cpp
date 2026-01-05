#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

inline string getKey(int x, int y, int z) {
  return to_string(x) + "," + to_string(y) + "," + to_string(z);
}

int findPaths(int x, int y, int m, int n, int currMove, int maxMove, unordered_map<string, int>& occured)
{
  // cout << x << " " << y << " " << currMove << endl;

  if (currMove > maxMove) {
    return 0;
  }

  if (x < 0 || y < 0 || x >= m || y >= n) {
    return 1;
  }

  string key = getKey(x, y, currMove);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  int up =     findPaths(x,     y - 1, m, n, currMove + 1, maxMove, occured) % MOD;
  int down =   findPaths(x,     y + 1, m, n, currMove + 1, maxMove, occured) % MOD;
  int left =   findPaths(x - 1, y,     m, n, currMove + 1, maxMove, occured) % MOD;
  int right =  findPaths(x + 1, y,     m, n, currMove + 1, maxMove, occured) % MOD;

  occured[key] = (((up + down) % MOD + left) % MOD + right) % MOD;

  return occured[key];
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
  unordered_map<string, int> occured;

  return findPaths(
    startRow, startColumn,
    m, n,
    0, maxMove,
    occured
  );
}

void solution()
{
  int m, n, maxMove, startRow, startColumn;

  cin >> m >> n >> maxMove >> startRow >> startColumn;

  cout << findPaths(m, n, maxMove, startRow, startColumn) << endl;
}

int main()
{
  solution();

  return 0;
}
