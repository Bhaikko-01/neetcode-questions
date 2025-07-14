/**
 * 1. Stack and Greedy - O(n)
 *      Try to rule out balanced paranthesis by using stack
 *      Final answer is stack size which are left unbalanced
 *      This approach works because we only need number of brackets
 *        and not balanced paranthesis
 */

#include <bits/stdc++.h>

using namespace std;

int minAddToMakeValid(string s)
{
  stack<char> pending;

  for (char x: s) {
    if (x == '(') {
      pending.push(x);
    } else {
      if (pending.empty()) {
        pending.push(x);
      } else if (pending.top() == '(') {
        pending.pop();
      } else {
        pending.push(x);
      }
    }
  }

  return pending.size();
}

void solution()
{
  string s;
  cin >> s;

  cout << minAddToMakeValid(s) << endl;
}

int main()
{
  solution();

  return 0;
}
