/**
 * 1. Backtracking
 *      Similar to palindrome-partitioning
 *        Answer possible if num of substrings count more than 2. Consider this in base case
 *        count increase if substring integer value is one less than prev substring integer value
 *        Maintain prevString to check difference with
 *      stoi can be used.
 *        In questions, had to implement to string difference method manually
 */

#include <bits/stdc++.h>

using namespace std;

string trim(string s)
{
  int i = 0;

  int n = s.size();

  while (i < n && s[i] == '0') {
    i++;
  }

  return s.substr(i);
}

bool validStringGroup(string first, string second)
{
  string firstWithoutTrailing = trim(first);
  string secondWithoutTrailing = trim(second);

  if (firstWithoutTrailing == "") {
    return false;
  }

  if (secondWithoutTrailing == "") {
    return firstWithoutTrailing == "1";
  }

  int firstWithoutTrailingSize = firstWithoutTrailing.size();
  int secondWithoutTrailingSize = secondWithoutTrailing.size();


  string lastI = firstWithoutTrailing.substr(firstWithoutTrailing.size() - 1, 1);
  string lastJ = secondWithoutTrailing.substr(secondWithoutTrailing.size() - 1, 1);

  if (firstWithoutTrailing == secondWithoutTrailing) {
    return false;
  }

  int lastIInt = stoi(lastI);
  int lastJInt = stoi(lastJ);


  if (lastIInt - lastJInt != 1 && lastIInt != 0 && lastJInt != 9) {
    return false;
  }

  if (lastIInt != 0 && lastJInt == 9 &&
      firstWithoutTrailingSize == 1 && secondWithoutTrailingSize == 1) {
    return false;
  }

  if (lastIInt == 0 && lastJInt == 9) {
    int x = firstWithoutTrailingSize - 2;

    while (x >= 0 && firstWithoutTrailing[x] == '0') {
      firstWithoutTrailing[x] = '9';
      x--;
    }

    firstWithoutTrailing[x] = to_string(stoi(firstWithoutTrailing.substr(x, 1)) - 1)[0];
  }

  int x = firstWithoutTrailingSize - 2;
  int y = secondWithoutTrailingSize - 2;

  while (x >= 0 && y >= 0) {
    if (firstWithoutTrailing[x] != secondWithoutTrailing[y]) {
      return false;
    }

    x--;
    y--;
  }

  if (firstWithoutTrailing[0] == '0') {
    return x == 0 && y == -1;
  } else {
    return x == -1 && y == -1;
  }
}

bool splitString(string& s, int currIndex, string lastString, int count)
{
  int n = s.size();

  if (currIndex > n) {
    return false;
  }

  if (currIndex == n) {
    return count >= 2;
  }

  for (int size = 1; currIndex + size <= n; size++) {
    string currString = s.substr(currIndex, size);

    bool currConditionMet = lastString == "" || validStringGroup(lastString, currString);

    if (currConditionMet) {
      bool possibleAns = splitString(s, currIndex + size, currString, count + 1);

      if (possibleAns) {
        return true;
      }
    }
  }

  return false;
}

bool splitString(string s)
{
  return splitString(s, 0, "", 0);
}

void solution()
{
  string s;
  cin >> s;

  cout << splitString(s) << endl;

  // string a, b;
  // cin >> a >> b;

  // cout << validStringGroup(a, b) << endl;
}

int main()
{
  solution();

  return 0;
}
