#include <bits/stdc++.h>

using namespace std;

int maxUniqueSplit(string s, int index, string currSubString, unordered_map<string, bool>& occured)
{
  int n = s.size();

  if (index == n) {
    return occured.size();
  }

  string newSubstring = currSubString + s[index];
  int includingCurr = INT_MIN;

  if (occured.find(newSubstring) == occured.end()) {
    occured[newSubstring] = true;
    includingCurr = maxUniqueSplit(s, index + 1, "", occured);
    occured.erase(newSubstring);
  }

  int excludingCurr = maxUniqueSplit(s, index + 1, newSubstring, occured);

  return max(includingCurr, excludingCurr);
}

int maxUniqueSplit(string s)
{
  unordered_map<string, bool> occured;

  return maxUniqueSplit(s, 0, "", occured);
}

void solution()
{
  string s;
  cin >> s;

  cout << maxUniqueSplit(s) << endl;
}

int main()
{
  solution();

  return 0;
}
