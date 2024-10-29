/**
 * 1. Track closed bracket count - O(n)
 *      Maintain currClosedBrackets count as that number will need to be nullified by using opening brackets
 *      Maintain maxClosedBrackets as each point as that number is number of swaps required
 *      After maxClosedBrackets determined after complete iteration, each swap fixes two closed brackets
 *        hence, ans = (maxClosedBrackets + 1) / 2;
 */

#include <bits/stdc++.h>

using namespace std;

int minSwaps(string s)
{
  int n = s.size();

  int maxClosedBrackets = 0;
  int currClosedBrackets = 0;

  for (char x: s) {
    if (x == '[') {
      currClosedBrackets--;
    } else {
      currClosedBrackets++;
    }

    maxClosedBrackets = max(maxClosedBrackets, currClosedBrackets);
  }

  return (maxClosedBrackets + 1) / 2;
}

void solution()
{
  string s;
  cin >> s;

  cout << minSwaps(s) << endl;
}

int main()
{
  solution();

  return 0;
}
