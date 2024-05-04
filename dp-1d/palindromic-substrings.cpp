/**
 * Same as longest-palindrome-substring. No need to track max length. Just increment count
*/

#include <bits/stdc++.h>

using namespace std;

int countSubstrings(string s)
{
  int n = s.size();

  int count = 0;

  for (int i = 0; i < n; i++) {
    // Odd length
    int l = i, r = i;

    while (l >= 0 && r < n && s[l] == s[r]) {
      count++;

      l--;
      r++;
    }

    // Even length
    l = i; r = i + 1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      count++;

      l--;
      r++;
    }
  }

  return count;
}

void solution()
{
  string s;
  cin >> s;

  cout << countSubstrings(s) << endl;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    solution();
  }

  return 0;
}
