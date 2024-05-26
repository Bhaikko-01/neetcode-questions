/**
 * 1. Stack - O(n)
 *      Simulate the popped operations when trying to push
 *      Pop till top ele is same as popped[currIndex]
 *        increment currIndex
 *      return currIndex == n // This means we successfully performed all popped operations
*/

#include <bits/stdc++.h>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
  int n = pushed.size();

  stack<int> processing;

  int currPoppedIndex = 0;

  for (int x: pushed) {
    processing.push(x);

    while (!processing.empty() && popped[currPoppedIndex] == processing.top()) {
      processing.pop();
      currPoppedIndex++;
    }
  }

  return currPoppedIndex == n;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> pushed(n), popped(n);

  for (int i = 0; i < n; i++) {
    cin >> pushed[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> popped[i];
  }

  cout << validateStackSequences(pushed, popped) << endl;
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
