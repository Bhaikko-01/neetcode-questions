/**
 * 1. Iterative
 *      Each column in each row is separated by 2*(numRows-1) offset which is fixed for each starting value
 *      Mid values occur if row is not first or last
 *        midOffset = 2*(numRows-1-i)
 *        midValue = j + midOffset
 */

#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows)
{
  if (numRows == 1) {
    return s;
  }

  int n = s.size();

  string ans = "";
  int fixedOffset = 2 * (numRows - 1);

  for (int i = 0; i < numRows; i++) {
    for (int j = i; j < n; j += fixedOffset) {
      ans += s[j];

      if (i > 0 && i < numRows - 1) {
        int midOffset = (numRows - 1 - i) * 2;
        int midIndex = j + midOffset;

        if (midIndex < n) {
          ans += s[midIndex];
        }
      }
    }
  }

  return ans;
}

void solution()
{
  string s;
  int numRows;

  cin >> s >> numRows;

  cout << convert(s, numRows) << endl;
}

int main()
{
  solution();

  return 0;
}
