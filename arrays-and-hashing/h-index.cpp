/**
 * 1. Linear search - O(n)
 *      For every hIndex possible from 1 to n,
 *        check how many papers have atleast that hIndex
 *        If possible then that is one of answer,
 *          find maximum
 * 2. Sort - O(nlogn)
 *      Sort array
 *      Iterate each element then possibleHIndex = n - i
 *      If currCitation >= possibleHIndex then this is ans
 *        since all elements to right of currCitation will always be greater than currCitation
 *        This is ans
 *      As we move right, we have decreasing possibleHIndex so first match is ans
 *        if possibleHIndex doesnt satisfy condition then it can never be ans as element to right as less than possibleHIndex
 */

#include <bits/stdc++.h>

using namespace std;

int hIndex(vector<int>& citations)
{
  int n = citations.size();

  sort(citations.begin(), citations.end());

  for (int i = 0; i < n; i++) {
    int citation = citations[i];

    int possibleHIndex = n - i;

    if (citation >= possibleHIndex) {
      return possibleHIndex;
    }
  }

  return 0;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> citations(n);
  for (int i = 0; i < n; i++) {
    cin >> citations[i];
  }

  cout << hIndex(citations) << endl;
}

int main()
{
  solution();

  return 0;
}
