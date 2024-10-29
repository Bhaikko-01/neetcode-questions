/**
 * 1. Brute Force - O(3^n)
 *      Generate all subsequence palindromes and store indexes
 *      From all palindromes, get disjoint pairs and get max ans
 * 2. Bitmask - O(2^n)
 *      Generate bitmasks corresponding to subsequence picked
 *        maintain leftShiftOne to AND with current bitmask
 *        if leftShiftOne AND bitmask is not 0, then concat in currentPallindrome
 *      After processing currentMask, reverse currentPallindrome and check with currentPallindrome
 *      Maintain mapping of mask and length of palindrome
 *      Process mapping
 *        If two bitmask has AND as zero then they are disjoint
 *        process of pair of bitmask to get combined length and get max answer
 */

#include <bits/stdc++.h>

using namespace std;

// ! 1.
void palindromicSubsequence(string s, int l, int r, vector<int> current, vector<vector<int>>& possibleSubsequences)
{
  int n = s.size();

  if (l < 0 || r >= n) {
    return;
  }

  if (s[l] == s[r]) {
    vector<int> possible(current);

    // possible.insert(possible.begin(), l);
    possible.push_back(l);

    if (l != r) {
      possible.push_back(r);
    }

    possibleSubsequences.push_back(possible);

    palindromicSubsequence(s, l - 1, r + 1, possible, possibleSubsequences);
  }

  palindromicSubsequence(s, l - 1, r, current, possibleSubsequences);
  palindromicSubsequence(s, l, r + 1, current, possibleSubsequences);
}

// ! 1.
bool isDisjoinSubsequences(vector<int>& first, vector<int>& second)
{
  int n = first.size(),
      m = second.size();

  unordered_map<int, bool> firstMapping;
  for (int x: first) {
    firstMapping[x] = true;
  }

  for (int y: second) {
    if (firstMapping[y]) {
      return false;
    }
  }

  return true;
}

// ! 1.
int maxProduct2(string s)
{
  int n = s.size();

  vector<vector<int>> possibleSubsequences;

  vector<int> current;

  for (int i = 0; i < n; i++) {
    current = vector<int>();
    palindromicSubsequence(s, i, i, current, possibleSubsequences);

    current = vector<int>();
    palindromicSubsequence(s, i, i + 1, current, possibleSubsequences);
  }

  // for (auto x: possibleSubsequences) {
  //   for (int y: x) {
  //     cout << s[y] << " ( " << y << " ) - ";
  //     cout << s[y];
  //   }

  //   cout << endl;
  // }

  int ans = 0;
  int m = possibleSubsequences.size();
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      vector<int> first = vector<int>(possibleSubsequences[i]);
      vector<int> second = vector<int>(possibleSubsequences[j]);

      if (isDisjoinSubsequences(first, second)) {
        int len = first.size() * second.size();


        ans = max(ans, len);
      }
    }
  }

  return ans;
}

// ! 2.
unordered_map<int, int> generateMaskLenMapping(string s)
{
  int n = s.size();
  int last = pow(2, n);

  unordered_map<int, int> mapping;

  for (int mask = 1; mask < last; mask++) {
    string possiblePalindrome = "";
    int leftShiftOne = 1;

    for (int i = 0; i < n; i++) {
      if ((leftShiftOne & mask) != 0) {
        possiblePalindrome = possiblePalindrome + s[i];
      }

      leftShiftOne = leftShiftOne << 1;
    }

    string curr(possiblePalindrome);
    reverse(curr.begin(), curr.end());

    if (possiblePalindrome == curr) {
      mapping[mask] = curr.size();
    }
  }

  return mapping;
}

// ! 2.
int maxProduct(string s)
{
  unordered_map<int, int> mapping = generateMaskLenMapping(s);

  int n = s.size();
  int last = pow(2, n);

  int maxLen = 0;

  for (int i = 1; i < last; i++) {
    for (int j = i + 1; j < last; j++) {
      if (!(i & j)) {
        int currLen = mapping[i] * mapping[j];

        maxLen = max(maxLen, currLen);
      }
    }
  }

  return maxLen;
}

void solution()
{
  string s;
  cin >> s;

  cout << maxProduct(s) << endl;

  set<set<int>> x;
}

int main()
{
  solution();

  return 0;
}
