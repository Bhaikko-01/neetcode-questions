/**
 * 1. Brute Force - O(n^3)
 *      Generate all substrings
 *      For each substring, check if palinedrome
 *        Find max len substring this way
 * 2. Two Pointer - O(n^2)
 *      Consider each index as middle of a palindrome and check in both direction
 *        till where this can go as palindrome
 *      Two cases exists when considering middle element
 *        Odd case where both l = r = i
 *        Even case where l = i, r = i + 1
 *      These cases exists as palindrome can be of even and odd length
 *      This works because for each index, smallest possible substring is that index and it is palindrome
 *        after that, we expand in both directions to iteratively add equal elements and check if substring
 *        greater than current is also a palindrome too
 *        This would also take into account all substrings along with palindrome checking while generating substring
*/

#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s)
{
  int n = s.size();

  string maxPalindrome = "";
  int maxLen = 0;

  for (int i = 0; i < n; i++) {
    // Odd length
    int l = i, r = i;

    while (l >= 0 && r < n) {
      if (s[l] == s[r]) {
        int currLen = r - l + 1;

        if (maxLen < currLen) {
          maxPalindrome = s.substr(l, currLen);
          maxLen = currLen;
        }
      } else {
        break;
      }

      l--;
      r++;
    }

    // Even length
    l = i; r = i + 1;
    while (l >= 0 && r < n) {
      if (s[l] == s[r]) {
        int currLen = r - l + 1;

        if (maxLen < currLen) {
          maxPalindrome = s.substr(l, currLen);
          maxLen = currLen;
        }
      } else {
        break;
      }

      l--;
      r++;
    }
  }

  return maxPalindrome;
}

void solution()
{
  string s;
  cin >> s;

  cout << longestPalindrome(s) << endl;
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
