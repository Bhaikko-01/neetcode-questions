/**
 * 1. Similar to Koko Eating Banana where Binary Search is used on param
 *      and condition is tried to fullfill with mid value
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int minimizedMaximum(int n, vector<int>& quantities)
{
  int m = quantities.size();

  int r = *max_element(quantities.begin(), quantities.end());
  int l = 1;

  int ans = INT_MAX;

  while (l <= r) {
    int prodCount = (l + r) / 2;

    ll storeFullfilled = 0;

    for (int i = 0; i < m; i++) {
      storeFullfilled += ceil(quantities[i] / (float)prodCount);
    }

    if (storeFullfilled <= n) {
      ans = min(ans, prodCount);
      r = prodCount - 1;
    } else {
      l = prodCount + 1;
    }
  }

  return ans;
}

int minimizedMaximumBrute(int n, vector<int>& quantities)
{
  int m = quantities.size();

  int maxProdCount = *max_element(quantities.begin(), quantities.end());

  for (int prodCount = 1; prodCount <= maxProdCount; prodCount++) {
    ll storeFullfilled = 0;

    for (int i = 0; i < m; i++) {
      storeFullfilled += ceil(quantities[i] / (float)prodCount);
    }

    if (storeFullfilled <= n) {
      return prodCount;
    }
  }

  return -1;
}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<int> quantities(m);
  for (int i = 0; i < m; i++) {
    cin >> quantities[i];
  }

  cout << minimizedMaximum(n, quantities) << endl;
}

int main()
{
  solution();

  return 0;
}
