/**
 * 1. Stack usage - O(n)
 *      Process each type of character differently
 *      - '[', simply push
 *      - ']', process current block by extracting 'sentence' and 'number'. Append the result based on current top
 *      - 'num', check if currentTop is num. If yes, then append to that otherwise push
 *      - 'char', check if currentTop is char. If yes, then append to that otherwise push
 *      Final ans is on top of stack.
 */

#include <bits/stdc++.h>

using namespace std;

bool isSmallAlpha(char x) {
  return x >= 'a' && x <= 'z';
}

bool isNum(char x) {
  return x >= '0' && x <= '9';
}

string decodeString(string s)
{
  int n = s.size();

  stack<string> pending;
  pending.push("");

  for (int i = 0; i < n; i++) {
    string currEl = s.substr(i, 1);
    char currElChar = currEl[0];

    if (currEl == "[") {
      pending.push(currEl);
    } else if (currEl == "]") {
      string sent = pending.top();
      pending.pop();

      // Removing '['
      pending.pop();

      string num = pending.top();
      pending.pop();

      int numTimes = stoi(num);

      string combined = "";
      for (int i = 1; i <= numTimes; i++) {
        combined += sent;
      }

      string currTop = pending.top();
      if (isSmallAlpha(currTop[0])) {
        pending.pop();
        pending.push(currTop + combined);
      } else {
        pending.push(combined);
      }

    } else if (isSmallAlpha(currElChar)) {
      string currTop = pending.top();
      if (isSmallAlpha(currTop[0])) {
        pending.pop();
        pending.push(currTop + currEl);
      } else {
        pending.push(currEl);
      }
    } else {
      string currTop = pending.top();
      if (isNum(currTop[0])) {
        pending.pop();
        pending.push(currTop + currEl);
      } else {
        pending.push(currEl);
      }
    }
  }

  return pending.top();
}

void solution()
{
  string s;
  cin >> s;

  cout << decodeString(s) << endl;
}

int main()
{
  solution();

  return 0;
}
