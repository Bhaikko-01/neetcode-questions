/**
 * 1. Brute Force - O(n^3)
 *      Generate all subsequences of size 3 - O(n^3)
 *      Count all subsequences which are palindrome
 * 2. Bound calculation - O(26 * n)
 *      Find first and last occurence of each char
 *      Since length of 3 is required, extreme elements have to be same and middle can be anything
 *        For bounds of specific element, find all the unique elements between those indexes
 *        Number of unique elements between bounds is number of palindromic subsequence possible with that bound
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

int countPalindromicSubsequence(string s)
{
  int n = s.size();

  unordered_map<char, pp> firstAndLastOccurence;

  for (char x: s) {
    firstAndLastOccurence[x] = { -1, -1 };
  }

  for (int i = 0; i < n; i++) {
    if (firstAndLastOccurence[s[i]].first == -1) {
      firstAndLastOccurence[s[i]].first = i;
    }

    firstAndLastOccurence[s[i]].second = i;
  }

  int count = 0;

  // O(26)
  for (unordered_map<char, pp>::iterator i = firstAndLastOccurence.begin(); i != firstAndLastOccurence.end(); i++) {
    unordered_map<int, bool> occured;

    // O(n)
    for (int j = i->second.first + 1; j < i->second.second; j++) {
      occured[s[j]] = true;
    }

    count += occured.size();
  }

  return count;
}

void solution()
{
  string s;
  cin >> s;

  cout << countPalindromicSubsequence(s) << endl;
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
