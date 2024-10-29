/**
 * 1. Reduce n and k till base case - O(logN)
 *      At any row (n),
 *        first half of row is same as prev whole row
 *        second half of row is alternating group of 2 from prev row
 *      if k is in first half, call recursion with (n-1, k)
 *      else if k is in second half,
 *        reduce k to first half of row as it can be used to get from prev row
 *        if k is odd, newK is (k - halfOfCurrent + 1) => (n - 1, newK)
 *        else if k is even, newK is (k - halfOfCurrent - 1) => (n - 1, newK)
 *      Create base case for n=1, n=2
 */

#include <bits/stdc++.h>

using namespace std;

int kthGrammar(int n, int k)
{
  if (n == 1) {
    return 0;
  }

  if (n == 2) {
    return k == 1 ? 0 : 1;
  }

  int pow2nDividedBy4 = pow(2, n - 2);

  if (k <= pow2nDividedBy4) {
    return kthGrammar(n - 1, k);
  } else {
    int kMinusPower = k - pow2nDividedBy4;

    if (k & 1) {
      return kthGrammar(n - 1, kMinusPower + 1);
    } else {
      return kthGrammar(n - 1, kMinusPower - 1);
    }
  }
}

void solution()
{
  int n, k;
  cin >> n >> k;

  cout << kthGrammar(n, k) << endl;
}

int main()
{
  solution();

  return 0;
}
