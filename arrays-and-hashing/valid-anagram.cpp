/**
 * 1. Maintain occurence of each character - O(n) [S + T]
 *  Iterate over first word and store occurence through Hash
 *  Reduce occurence everything that character is found in other string
 *  If all occurence are zero, anagram otherwise not
 */

#include <bits/stdc++.h>

using namespace std;

// ! 1.
bool isAnagram(string s, string t)
{
  unordered_map<char, int> s_occurences;

  if (s.length() != t.length()) {
    return false;
  }

  for (int i = 0; i < s.length(); i++) {
    s_occurences[s[i]]++;
  }

  for (int i = 0; i < t.length(); i++) {
    s_occurences[t[i]]--;

    if (s_occurences[t[i]] < 0) {
      return false;
    }
  }

  for (unordered_map<char, int>::iterator it = s_occurences.begin(); it != s_occurences.end(); it++) {
    if (it->second != 0) {
      return false;
    }
  }

  return true;
}

void solution()
{
  string s, t;
  cin >> s >> t;

  cout << isAnagram(s, t) << endl;
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
