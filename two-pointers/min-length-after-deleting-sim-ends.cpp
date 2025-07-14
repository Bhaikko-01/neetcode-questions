/**
 * 1. Two Pointer - O(n)
 *      Maintain two pointers l, r
 *      If both values are same, delete with Greedy Approach
 *        If both have adjacent same as well, delete both
 *        If one has adjacent, delete that
 *      If window reaches size 1,
 *        Maintain cameFromDeleting which tells if size 1 is possible by deleting l,r
 *        If cameFromDeleting is true then ans is 0
 *        Else ans is 1
 *      Size 1 window is not considered to be substring containing same prefix and suffix
*/

#include <bits/stdc++.h>

using namespace std;

int minimumLength(string s)
{
  int n = s.size();

  int l = 0, r = n - 1;
  bool cameFromDeleting = false;

  while (l <= r) {
    if (s[l] == s[r]) {
      if (l == r) {
        return !cameFromDeleting;
      }

      if (s[l] == s[l + 1] && s[r] == s[r - 1]) {
        cameFromDeleting = true;
        l++;
        r--;
      } else if (s[l] != s[l + 1] && s[r] != s[r - 1]) {
        cameFromDeleting = false;
        l++;
        r--;
      } else if (s[l] == s[l + 1]) {
        l++;
      } else {
        r--;
      }
    } else {
      return r - l + 1;
    }
  }

  return 0;
}

void solution()
{
  string s;
  cin >> s;

  cout << minimumLength(s) << endl;
}

int main()
{
  solution();

  return 0;
}
