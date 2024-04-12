/**
 * 1. Using stack to do and undo - O(n) - [T + S]
 *    If it is opening bracket, push to stack
 *    If it is closing brack, check correct opening bracket is at top
 *      If yes -> continue
 *      If not -> return false
 *    In end, stack should be empty to check if unneccesary opening brackets exists
*/

#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
  stack<char> occuredParanthesis;

  for (char a: s) {
    if (a == '(' || a == '[' || a == '{') {
      occuredParanthesis.push(a);
    } else {
      if (occuredParanthesis.empty()) {
        return false;
      }

      if (a == ')' && occuredParanthesis.top() != '(') {
        return false;
      }

      if (a == ']' && occuredParanthesis.top() != '[') {
        return false;
      }

      if (a == '}' && occuredParanthesis.top() != '{') {
        return false;
      }

      occuredParanthesis.pop();
    }
  }

  return occuredParanthesis.empty();
}

void solution()
{
  string s;
  cin >> s;

  cout << isValid(s) << endl;
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
