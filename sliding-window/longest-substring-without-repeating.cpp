/**
 * 1. Two pointer with search for element behind - O(n^2) [T]
 *    Maintain l and r that would be sliding window for checking condition of non-repeating
 *    For every r index, check if s[r] occurs till l index, l <= i < r
 *      If s[i] found, currLength--;
 *      Else currLength++
 *    For each index, maxLength = max(maxLength, currLength)
 * 2. Optimise search of s[r] in "1." using Hashmap - O(n) [T + S]
 *    Before l++, occured[s[l]] = false // Removing the character from occured
 *      Removing and marking false works because we never let the frequency a letter more than 2 here
 * 3. Maintain index of last occured - O(n) [T + S] - NOT RELATED TO "1." and "2."
 *
 *
 *
 * ! General Way to handle sliding window problems
 * - Use for loop for 'r' till end to always increase window
 * - Make the window valid using while loop
 * - If window is valid, process it and continue
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1.
int lengthOfLongestSubstringBrute(string s)
{
  int n = s.length();

  int maxLength = 0,
      l = 0,
      r = 0,
      currLength = 0;

  while (l < n && r < n) {
    if (l == r) {
      currLength = 1;
      r++;
    } else {
      bool charFound = false;

      for (int i = r - 1; i >= l; i--) {
        if (s[r] == s[i]) {
          charFound = true;
          break;
        }
      }

      if (charFound) {
        currLength--;
        l++;
      } else {
        currLength++;
        r++;
      }
    }

    maxLength = max(maxLength, currLength);
  }

  return maxLength;
}

// ! 2.
int lengthOfLongestSubstring(string s)
{
  int n = s.length();

  unordered_map<char, bool> occured;

  int maxLength = 0,
      l = 0,
      r = 0,
      currLength = 0;

  while (l < n && r < n) {
    if (l == r) {
      occured[s[r]] = true;

      currLength = 1;
      r++;
    } else {
      if (occured[s[r]]) {
        occured[s[l]] = false;

        currLength--;
        l++;
      } else {
        occured[s[r]] = true;

        currLength++;
        r++;
      }
    }

    maxLength = max(maxLength, currLength);
  }

  return maxLength;
}

int lengthOfLongestSubstringX(string s)
{
  int n = s.length();

  unordered_map<char, bool> occured;

  int maxLength = 0,
      l = 0;

  for (int r = 0; r < n; r++) {
    while (occured[s[r]]) {
      occured[s[l]] = false;
      l++;
    }

    occured[s[r]] = true;

    int currLen = r - l + 1;
    maxLength = max(maxLength, currLen);
  }

  return maxLength;
}

void solution()
{
  string s;
  cin >> s;

  cout << lengthOfLongestSubstring(s) << endl;
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
