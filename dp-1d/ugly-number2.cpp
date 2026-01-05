/**
 * 1. Tree and Heap - O(nlogn)
 *      Visualize problem as tree where next number from current is its child
 *      Children of a number will be multiple of 2,3,5
 *      Pick min number and check if its nth number.
 *      Each number picked is guaranteed to be ugly since we only multiple 2,3,5
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int nthUglyNumber(int n)
{
  set<ll> pending;
  int numFound = 0;

  pending.insert(1);

  while (true) {
    ll top = *pending.begin();
    pending.erase(top);

    numFound++;

    if (numFound == n) {
      return top;
    }

    pending.insert(top * 2);
    pending.insert(top * 3);
    pending.insert(top * 5);
  }

  return 0;
}

void solution()
{
  int n;
  cin >> n;

  cout << nthUglyNumber(n) << endl;
}

int main()
{
  solution();

  return 0;
}
