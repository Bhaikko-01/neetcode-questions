#include <bits/stdc++.h>

using namespace std;

string customSortString(string order, string s)
{
  unordered_map<char, int> precedence;
  int currPrecendence = 0;

  for (char c: order) {
    precedence[c] = currPrecendence++;
  }

  sort(s.begin(), s.end(), [&precedence](char x, char y) -> bool {
    return precedence[x] < precedence[y];
  });

  return s;
}

void solution()
{
  string order, s;
  cin >> order >> s;

  cout << customSortString(order, s) << endl;
}

int main()
{
  solution();

  return 0;
}
