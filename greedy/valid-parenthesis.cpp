/**
 * 1. Backtracking - O(n*3^n)
 *      Do normal parenthesis checking using stack
 *      If * is reached, run backtracking using three possibilities - '(', ')', ' '
 *        If all returns false then not possible otherwise return true
 *      Pass current stack state to each recursive call
 * 2. Greedy = O(n)
 *      Maintain two variables, maxLeftOpenParan and minLeftOpenParan
 *        maxLeftOpenParan indicates numOfOpenParans when wildcard is considered (
 *        minLeftOpenParan indicates numOfOpenParans when wildcard is considered )
 *      If currChar is (
 *        increment both variables
 *      If currChar is )
 *        decrement both variables
 *      If currChar is '*'
 *        increment maxLeft and decrement minLeft
 *      If minLeft reaches less than zero than we reset it to zero as it indicates wrong choices till now
 *      If maxLeft reaches zero then no possible answer
 *      If in end, no leftOpen Parans exist like in stack of normal balanced check
 *        ans is true else false
*/

#include <bits/stdc++.h>

using namespace std;

bool checkValidStringBrute(string s, stack<char> pending, int currIndex)
{
  int n = s.size();

  if (currIndex == n && pending.empty()) {
    return true;
  }

  for (int i = currIndex; i < n; i++) {
    if (s[i] == '(') {
      pending.push(s[i]);
    } else if (s[i] == ')') {
      if (pending.size() && pending.top() == '(') {
        pending.pop();
      } else {
        return false;
      }
    } else if (s[i] == '*') {
      s[i] = '(';
      if (checkValidStringBrute(s, pending, i)) {
        return true;
      }

      s[i] = ')';
      if (checkValidStringBrute(s, pending, i)) {
        return true;
      }

      s[i] = ' ';
      if (checkValidStringBrute(s, pending, i)) {
        return true;
      }
    }
  }

  return pending.empty();
}

bool checkValidStringBrute(string s)
{
  stack<char> pending;

  return checkValidStringBrute(s, pending, 0);
}

bool checkValidString(string s)
{
  int n = s.size();
  int maxLeftOpen = 0, // Track number of open left paran when wildcard was leftParan
      minLeftOpen = 0; // Track number of open left paran when wildcard was rightParan

  for (char x: s) {
    if (x == '(') {
      maxLeftOpen++;
      minLeftOpen++;
    } else if (x == ')') {
      maxLeftOpen--;
      minLeftOpen = max(0, minLeftOpen - 1);

      if (maxLeftOpen < 0) {
        return false;
      }
    } else if (x == '*') {
      maxLeftOpen++;
      minLeftOpen = max(0, minLeftOpen - 1);
    }
  }

  return minLeftOpen == 0;
}

void solution()
{
  string s;
  cin >> s;

  cout << checkValidString(s) << endl;
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
