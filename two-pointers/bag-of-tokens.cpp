/**
 * Intution
 *    1. Play small power coins up to use min power
 *    2. Play big power counts down to gain max power
 *        - Dont decrease score if only one element left to process as that will only decrease score
 */

#include <bits/stdc++.h>

using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power)
{
  int n = tokens.size();

  sort(tokens.begin(), tokens.end());

  int l = 0,
      r = n - 1,
      points = 0;

  while (l <= r) {
    if (power >= tokens[l]) {
      points++;
      power -= tokens[l];

      l++;
    } else if (points >= 1) {
      if (l == r) {
        break;
      }

      points--;
      power += tokens[r];

      r--;
    } else {
      break;
    }
  }

  return points;
}

void solution()
{
  int n, power;
  cin >> n >> power;

  vector<int> tokens(n);
  for (int i = 0; i < n; i++) {
    cin >> tokens[i];
  }

  cout << bagOfTokensScore(tokens, power) << endl;
}

int main()
{
  solution();

  return 0;
}
