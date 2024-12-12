/**
 * 1. Stack - O(n)
 *      Maintain stack of element and occurence
 *        If top element is same as currEle, Check its occurence
 *          If exceeds 'k', pop it
 *          Else update the occurence
 *        Else simply push the currEle with 1 occurence
 *      Rebuild string with stack in end
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> pp;

string removeDuplicates(string s, int k)
{
  int n = s.size();

  stack<pp> pending;

  for (int i = 0; i < n; i++) {
    char x = s[i];

    if (pending.empty()) {
      pending.push({ x, 1 });
    } else {
      pp top = pending.top();

      if (top.first == x) {
        pending.pop();

        top.second += 1;

        if (top.second < k) {
          pending.push(top);
        }
      } else {
        pending.push({ x, 1 });
      }
    }
  }

  string ans = "";

  while (!pending.empty()) {
    pp top = pending.top();
    pending.pop();

    ans = string(top.second, top.first) + ans;
  }

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  int k;
  cin >> k;

  cout << removeDuplicates(s, k) << endl;
}

int main()
{
  solution();

  return 0;
}
