/**
 * 1. Iterative from Start
 *      Maintain precedence and value of each symbol
 *      Compare with next elements
 *        If last element then process that only
 *      If nextPrecendence is strictly greater than currPrecedence then subtract currValue
 *      Else add currValue
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

unordered_map<char, pp> romanMapping = {
  { 'I', { 1, 1 } },
  { 'V', { 2, 5 } },
  { 'X', { 3, 10 } },
  { 'L', { 4, 50 } },
  { 'C', { 5, 100 } },
  { 'D', { 6, 500 } },
  { 'M', { 7, 1000 } }
};

int romanToInt(string s)
{
  int n = s.size();
  int ans = 0;

  for (int i = 0; i < n; i++) {
    char curr = s[i];
    int currValue = romanMapping[curr].second;
    int currPrecedence = romanMapping[curr].first;

    if (i == n - 1) {
      ans += currValue;
      break;
    }

    char next = s[i + 1];
    int nextPrecendence = romanMapping[next].first;
    int nextValue = romanMapping[next].second;

    if (nextPrecendence <= currPrecedence) {
      ans += currValue;
    } else if (nextPrecendence > currPrecedence) {
      ans += -currValue;
    }
  }

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  cout << romanToInt(s) << endl;
}

int main()
{
  solution();

  return 0;
}
