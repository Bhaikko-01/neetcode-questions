/**
 * 1. Sliding Window - O(n)
 *      Maintain cost of current window
 *      If currCost gets more than maxCost then decrease window till validCost exists
 *      check if currCost is valid
 *        ans = max(ans, r - l + 1)
 */

#include <bits/stdc++.h>

using namespace std;

int calCost(char a, char b) {
  return abs((int)a - (int)b);
}

int equalSubstring(string s, string t, int maxCost)
{
  int n = s.size();

  int l = 0,
      r = 0,
      currCost = 0,
      ans = 0;

  while (r < n) {
    currCost += calCost(s[r], t[r]);

    while (l <= r && currCost > maxCost && currCost >= 0) {
      int lessCost = calCost(s[l], t[l]);

      currCost -= lessCost;

      l++;
    }

    if (currCost <= maxCost) {
      ans = max(ans, r - l + 1);
    }

    r++;
  }

  return ans;
}

void solution()
{
  string s, t;
  cin >> s >> t;

  int maxCost;
  cin >> maxCost;

  cout << equalSubstring(s, t, maxCost) << endl;
}

int main()
{
  solution();

  return 0;
}
