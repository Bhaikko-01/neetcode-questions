/**
 * 1. Brute Force - O(n^2)
 *    Get all substrings
 *    In each substring
 *      Find non-max element occuring count
 *    If non-max element occuring count <= k, then subStr is valid -> return subStr.length
 *      ans = max(ans, subStr.length - countOfMaxElement) -> Maximize this
 *    Else not valid -> return -1
 * 2. Sliding window to Maximize equation - O(n)
 *    Maintain two pointers - l and r that would be subStr length
 *    At each iteration, check maxOccuringElement in occurence hash
 *    The shifting of window works because,
*       if window of size 'n is not valid for a specific size based on k,
 *      it will not be valid for any size greater n,
 *      so no need to increase window size
 *    If nonMaxOccuringCount <= k
 *      ans = max(ans, subStrLen); occurent[s[r]]++; r++;
 *    Else
 *      occurence[s[l]]--; l++;
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1.
int replaceCharacter(string subStr, int k)
{
  int n = subStr.size();

  unordered_map<char, int> occurence;

  for (char s: subStr) {
    occurence[s]++;
  }

  if (occurence.size() == 1) {
    return n;
  }

  int maxElOccurence = 0;
  char maxEl;

  for (auto it = occurence.begin(); it != occurence.end(); it++) {
    if (maxElOccurence < it->second) {
      maxElOccurence = it->second;
      maxEl = it->first;
    }
  }

  // ! The equation we are trying to maximize
  int otherElOccurence = n - occurence[maxEl];

  return otherElOccurence <= k ? n : -1;
}

// ! 1.
int characterReplacementBrute(string s, int k)
{
  int n = s.length();
  int ans = 0;

  for (int subStrSize = 1; subStrSize <= n; subStrSize++) {
    for (int i = 0; i + subStrSize <= n; i++) {
      string currSubstr = s.substr(i, subStrSize);
      ans = max(ans, replaceCharacter(currSubstr, k));
    }
  }

  return ans;
}

// ! 2.
int characterReplacement(string s, int k)
{
  int n = s.length();
  int ans = 0,
      l = 0,
      r = 0;

  unordered_map<char, int> occurence;
  occurence[s[0]]++;

  while (l < n && r < n) {
    int subStrLen = r - l + 1;

    int maxElOccurence = 0;
    char maxEl;

    // ! This loop will be max executed 26 times
    for (auto it = occurence.begin(); it != occurence.end(); it++) {
      if (maxElOccurence < it->second) {
        maxElOccurence = it->second;
        maxEl = it->first;
      }
    }

    int otherElOccurrence = subStrLen - occurence[maxEl];

    // ! Based on the fact that if subStr=x doesnt work with k then all subStr>x wont work either
    if (otherElOccurrence <= k) {
      ans = max(ans, subStrLen);
      r++;
      occurence[s[r]]++;
    } else {
      occurence[s[l]]--;
      l++;
    }
  }

  return ans;
}

void solution()
{
  string s;
  int k;

  cin >> s >> k;

  cout << characterReplacement(s, k) << endl;
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
