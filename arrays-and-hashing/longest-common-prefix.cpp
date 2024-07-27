/**
 * 1. Check all strings - O(m*n)
 *      Get string of minLen from all strings
 *        This will be the max possible len
 *      Check specific element at each index of all strings
 *        If anyFails, then substring till prev index is answer
 */

#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
  int n = strs.size();

  int minStringLen = INT_MAX;
  for (string s: strs) {
    if (s.size() < minStringLen) {
      minStringLen = s.size();
    }
  }

  int index = 0;

  while (index < minStringLen) {
    char requiredEqual = strs[0][index];

    for (int i = 1; i < n; i++) {
      if (requiredEqual != strs[i][index]) {
        return strs[0].substr(0, index);
      }
    }

    index++;
  }

  return strs[0].substr(0, minStringLen);
}

void solution()
{
  int n;
  cin >> n;

  vector<string> strs(n);
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
  }

  cout << longestCommonPrefix(strs) << endl;
}

int main()
{
  solution();

  return 0;
}
