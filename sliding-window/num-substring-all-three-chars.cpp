#include <bits/stdc++.h>

using namespace std;

bool hasAllThreeChars(unordered_map<char, int>& occ)
{
  return (
    occ['a'] > 0 &&
    occ['b'] > 0 &&
    occ['c'] > 0
  );
}

int numberOfSubstrings(string s)
{
  int n = s.size();

  int l = 0,
      r = 0;

  unordered_map<char, int> occurence;

  int ans = 0;

  for (r = 0; r < n; r++) {
    occurence[s[r]]++;

    while (hasAllThreeChars(occurence)) {
      int elRightToWindow = n - 1 - r;

      ans += elRightToWindow + 1;

      occurence[s[l]]--;
      l++;
    }
  }

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  cout << numberOfSubstrings(s) << endl;
}

int main()
{
  solution();

  return 0;
}
