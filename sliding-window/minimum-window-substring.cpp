/**
 * 1. Brute Force - O(n^2)
 *    Generate all substrings
 *    Create occurence mapping for 't' and all subStrs
 *    For each element of 't',
 *      if tOccurence[t[i]] > sOccurence[t[i]] => not valid subStr
 *        This is because, subStr will not be able to hold tOccurence
 *      else if all tOccurence satisfies above condition
 *        ans is that subStr
 * 2. Sliding Window O(n)
 *    Two pointer approach where l and r are subStr pointers
 *    maintain tOccurrence and subStrOccurence
 *    if solution found by comparing tOccurence and subStrOccurence
 *      increase 'l' to find solution of smaller windows
 *        ans = min(ans, currSubstr)
 *    else find solution with bigger window
 *      increase 'r' and continue loop
*/

#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<char, int> charIntMapping;

// ! 1
string minWindowBrute(string s, string t)
{
  int m = s.length(),
      n = t.length();

  charIntMapping tOccurence;
  for (char a: t) {
    tOccurence[a]++;
  }

  for (int subStrSize = 1; subStrSize <= m; subStrSize++) {
    for (int i = 0; i + subStrSize <= m; i++) {
      string subStr = s.substr(i, subStrSize);
      charIntMapping sOccurence;

      for (char a: subStr) {
        sOccurence[a]++;
      }

      bool invalidComparison = false;

      for (auto it = tOccurence.begin(); it != tOccurence.end(); it++) {
        if (it->second > sOccurence[it->first]) {
          invalidComparison = true;
        }
      }

      if (!invalidComparison) {
        return subStr;
      }
    }
  }

  return "";
}

// ! 2.
string minWindow(string s, string t)
{
  int m = s.length(),
      n = t.length();

  charIntMapping tOccurence, sOccurence;
  for (char a: t) {
    tOccurence[a]++;
  }

  int l = 0,
      r = 0;
  string ans = "";

  sOccurence[s[l]]++;

  while (l < m && r < m) {
    bool invalidComparison = false;

    for (auto it = tOccurence.begin(); it != tOccurence.end(); it++) {
      if (it->second > sOccurence[it->first]) {
        invalidComparison = true;
      }
    }

    if (invalidComparison) {
      r++;
      sOccurence[s[r]]++;
    } else {
      string currAns = s.substr(l, r - l + 1);
      if (ans == "" || currAns.length() < ans.length()) {
        ans = currAns;
      }

      sOccurence[s[l]]--;
      l++;
    }
  }

  return ans;
}

void solution()
{
  string s, t;
  cin >> s >> t;

  cout << minWindow(s, t) << endl;
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
