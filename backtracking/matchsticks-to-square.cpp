/**
 * 1. Backtracking - O(4^n)
 *      Take decision whether to put matchstick on left, right, up or down
 *      Check sum if divisble by 4. If divisible then matchsticks may be possible otherwise false
 *      Backtracking required to check if combination possible since matchstick break not possible
 *        Hence need to check if creation possible and not get answer based on perimeter
 *      For backtracking,
 *        Try placing currMatchStick at each position
 *        If side reaches more than possibleSide then return false
 *        If last index reached, then check all sides possible
 *      For reducing time, sort and reverse to discard bigger side in beginning only.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool makesquare(vector<int>& matchsticks, int index,
                int a, int b, int c, int d, ll possibleSide)
{
  int n = matchsticks.size();

  if (a > possibleSide || b > possibleSide || c > possibleSide || d > possibleSide) {
    return false;
  }

  if (index == n) {
    return a == b && b == c && c == d;
  }

  int currMatch = matchsticks[index];

  return makesquare(matchsticks, index + 1, a + currMatch, b, c, d, possibleSide) ||
         makesquare(matchsticks, index + 1, a, b + currMatch, c, d, possibleSide) ||
         makesquare(matchsticks, index + 1, a, b, c + currMatch, d, possibleSide) ||
         makesquare(matchsticks, index + 1, a, b, c, d + currMatch, possibleSide);
}

bool makesquare(vector<int>& matchsticks)
{
  ll sum = 0;
  for (int matchstick: matchsticks) {
    sum += matchstick;
  }

  if (sum % 4 != 0) {
    return false;
  }

  int possibleSide = sum / 4;

  sort(matchsticks.begin(), matchsticks.end());
  reverse(matchsticks.begin(), matchsticks.end());

  return makesquare(matchsticks, 0, 0, 0, 0, 0, possibleSide);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> matchsticks(n);
  for (int i = 0; i < n; i++) {
    cin >> matchsticks[i];
  }

  cout << makesquare(matchsticks) << endl;
}

int main()
{
  solution();

  return 0;
}
