/**
 * 1. Stack - O(n)
 *      Need to undo an operation if '*' uncountered hence stack used
 *      If current el in string is '*'
 *        pop from stack
 *      else
 *        push to stack
 *      In end, string will be reversed inside stack
 *        handle reversing as well
*/

#include <bits/stdc++.h>

using namespace std;

string removeStars(string s)
{
  int n = s.size();

  stack<char> pending;

  for (char x: s) {
    if (x == '*') {
      pending.pop();
    } else {
      pending.push(x);
    }
  }

  string ans = "";
  while (!pending.empty()) {
    ans += pending.top();
    pending.pop();
  }

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  cout << removeStars(s) << endl;
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
