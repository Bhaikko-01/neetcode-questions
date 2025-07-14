/**
 * 1. Stack - O(n)
 *      Maintain stack of pending and string for curr processing
 *      Take decision based on current character
 *        '(' -> Push currPending to stack and reset currPending
 *        ')' -> Reverse currPending and make it top() + currPending
 *         *  -> Append to currPending
 *      Final answer is currPending
 */

#include <bits/stdc++.h>

using namespace std;

string reverseParentheses(string s)
{
  int n = s.size();
  stack<string> pending;

  string currPending = "";

  for (char x: s) {
    if (x == '(') {
      pending.push(currPending);
      currPending = "";
    } else if (x == ')') {
      reverse(currPending.begin(), currPending.end());
      currPending = pending.top() + currPending;
      pending.pop();
    } else {
      currPending += x;
    }
  }

  return currPending;
}

void solution()
{
  string s;
  cin >> s;

  cout << reverseParentheses(s) << endl;
}

int main()
{
  solution();

  return 0;
}
