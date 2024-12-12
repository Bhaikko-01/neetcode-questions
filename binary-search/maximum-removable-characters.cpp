/**
 * 1. Linear Search - O(nk)
 *      Try every index of removable which satisfy the condition
 *      Condition: Removing indexes from 's' and 'p' still being subsequence of 's'
 *      To Check if p is subsequence of s, Linear matching is enough and complete
 *        Check for every index of 'p', a value in 's' exists sequentially
 *        Also check if sIndex is removed or not using removableMapping
 * 2. Binary search - O((n+k)logk)
 *      Instead of linear searching of indexes in removable, use binary search
 *      For mid, all values before it is marked as removed
 *      Then 's' and 'p' are checked if they are valid subsequence
 *        while keeping track of removed elements
 */

#include <bits/stdc++.h>

using namespace std;

// ! 1. & 2.
bool isValidK(string s, string p, vector<bool>& removable)
{
  int n = s.size(),
      m = p.size();

  int sIndex = 0,
      pIndex = 0;

  while (sIndex < n && pIndex < m) {
    if (
      !removable[sIndex] &&
      s[sIndex] == p[pIndex]
    ) {
      pIndex++;
    }

    sIndex++;
  }

  // * Checking if all pIndex values got matched and pIndex reached end
  return pIndex == m;
}

// ! 2.
int maximumRemovals(string s, string p, vector<int>& removable)
{
  int n = removable.size();

  int l = 0,
      r = n - 1;

  int maxAns = -1;

  while (l <= r) {
    int mid = (l + r) / 2;

    vector<bool> removableMapping(s.size(), false);

    for (int i = 0; i <= mid; i++) {
      removableMapping[removable[i]] = true;
    }

    if (isValidK(s, p, removableMapping)) {
      maxAns = max(mid, maxAns);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return maxAns + 1;
}

// ! 1.
int maximumRemovals2(string s, string p, vector<int>& removable)
{
  int n = removable.size();

  vector<bool> removableMapping(s.size(), false);

  for (int k = 0; k < n; k++) {
    removableMapping[removable[k]] = true;

    if (!isValidK(s, p, removableMapping)) {
      return k;
    }
  }

  return n;
}

void solution()
{
  int n;
  cin >> n;

  string s, p;
  cin >> s >> p;

  vector<int> removable(n);
  for (int i = 0; i < n; i++) {
    cin >> removable[i];
  }

  cout << maximumRemovals(s, p, removable) << endl;
}

int main()
{
  solution();

  return 0;
}
