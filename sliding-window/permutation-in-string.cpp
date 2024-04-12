/**
 * 1. BruteForce - O(n * 26) ~= O(n)
 *    Generate all substrings of length of s1
 *    Match occurence mapping of both s1 and sub-strings of s2
 *      This will check for valid permutation
 * 2. Sliding window - O(26 * n) ~= O(n)
 *    Slide window of size s1.size
 *    If comparePermutation is true => return true
 *    Else updateOccurences and l++, r++
*/

#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<char, int> charIntMapping;

// ! 1.
bool comparePermutation(charIntMapping first, charIntMapping second)
{
  for (auto it = first.begin(); it != first.end(); it++) {
    if (it->second != second[it->first]) {
      return false;
    }
  }

  return true;
}

// ! 1.
bool checkInclusionBrute(string s1, string s2)
{
  charIntMapping s1Occurence, s2Occurence;

  for (char a: s1) {
    s1Occurence[a]++;
  }

  int subStrSize = s1.size();
  int n = s2.size();

  for (int i = 0; i + subStrSize <= n; i++) {
    string subStr = s2.substr(i, subStrSize);

    // ! This is repeated work. Recreating this map for each substring comparison
    // ! Can be done using Sliding window
    for (char a: subStr) {
      s2Occurence[a]++;
    }

    if (comparePermutation(s1Occurence, s2Occurence)) {
      return true;
    }

    s2Occurence.clear();
  }

  return false;
}

// ! 2.
bool checkInclusion(string s1, string s2)
{
  charIntMapping s1Occurence, s2Occurence;

  for (char a: s1) {
    s1Occurence[a]++;
  }

  int subStrSize = s1.size();
  int l = 0, r = subStrSize - 1;
  int n = s2.size();

  for (char a: s2.substr(l, subStrSize)) {
    s2Occurence[a]++;
  }

  while (l < n && r < n) {
    if (comparePermutation(s1Occurence, s2Occurence)) {
      return true;
    } else {
      s2Occurence[s2[l]]--;
      l++;
      r++;
      s2Occurence[s2[r]]++;
    }
  }

  return false;
}

void solution()
{
  string s1, s2;
  cin >> s1 >> s2;

  cout << checkInclusion(s1, s2) << endl;
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
