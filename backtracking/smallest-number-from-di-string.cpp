/**
 * 
 */

#include <bits/stdc++.h>

using namespace std;

void smallestNumber(string& pattern, int index, string currNumber, string& ans, unordered_map<char, bool>& taken)
{
  int n = pattern.size();

  if (index == n + 1) {
    if (ans == "" || currNumber < ans) {
      ans = currNumber;
    }

    return;
  }

  if (currNumber == "") {
    for (char i = '1'; i <= '9'; i++) {
      if (!taken[i]) {
        taken[i] = true;
        smallestNumber(pattern, index + 1, string(1, i), ans, taken);
        taken[i] = false;
      }
    }
  } else {
    char currDI = pattern[index - 1];
    char currLetter = currNumber[index - 1];

    if (currDI == 'I') {
      for (char i = currLetter + 1; i <= '9'; i++) {
        if (!taken[i]) {
          taken[i] = true;
          smallestNumber(pattern, index + 1, currNumber + i, ans, taken);
          taken[i] = false;
        }
      }
    } else if (currDI == 'D') {
      for (char i = currLetter - 1; i >= '1'; i--) {
        if (!taken[i]) {
          taken[i] = true;
          smallestNumber(pattern, index + 1, currNumber + i, ans, taken);
          taken[i] = false;
        }
      }
    }
  }
}

string smallestNumber(string pattern)
{
  string ans = "";
  unordered_map<char, bool> taken;

  smallestNumber(pattern, 0, "", ans, taken);

  return ans;
}

void solution()
{
  string pattern;
  cin >> pattern;

  string ans = smallestNumber(pattern);

  cout << ans << endl;
}

int main()
{
  solution();

  return 0;
}
