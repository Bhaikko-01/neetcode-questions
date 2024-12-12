/**
 * 1. Monotonic increasing Stack + Greedy - O(n)
 *      Intituion behind greedy approach is
 *        - If number is in increasing order, then numbers from last can be removed if pendingRemoves Permit
 *        - If there is a number greater than upcoming numbers, then remove that instead if pendingRemoves permit
 *        The above two points gives smallest number
 *      Maintain monotonic increasing stack to track if upcoming numbers are smaller. Remove the previous numbers if
 *        pendingRemoves permit
 *      If monotonic stack is obtained, combine it into final string after removing numbers from last if pendingRemoves permit
 *      Handle case of empty string and trailing zeros
 *
 *      Note: Stack used as we will need to undo the tracked numbers based on future numbers
 */

#include <bits/stdc++.h>

using namespace std;

string removeKdigits(string num, int k)
{
  int n = num.size();
  int pendingRemoves = k;

  stack<int> monotonicIncreasing;

  for (int i = 0; i < n; i++) {
    int currNum = num[i] - '0';

    while (
      !monotonicIncreasing.empty() &&
      monotonicIncreasing.top() > currNum &&
      pendingRemoves > 0
    ) {
      monotonicIncreasing.pop();
      pendingRemoves--;
    }

    monotonicIncreasing.push(currNum);
  }

  string ans = "";
  while (!monotonicIncreasing.empty()) {
    if (pendingRemoves <= 0) {
      // Memory optimisation to avoid Memory Exceeded on leetcode
      // We just need to simply add top element at front of 'ans' string
      // Here, we add it to last and reverse at end
      char converted = (char)(48 + monotonicIncreasing.top());
      ans.push_back(converted);
    } else {
      pendingRemoves--;
    }

    monotonicIncreasing.pop();
  }

  // Reversing as in 'Memory optimisation', we inserted 'top' elements at last
  reverse(ans.begin(), ans.end());

  if (ans == "") {
    return "0";
  }

  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] != '0') {
      return ans.substr(i);
    }
  }

  return "0";
}

void solution()
{
  string num;
  cin >> num;

  int k;
  cin >> k;

  cout << removeKdigits(num, k) << endl;
}

int main()
{
  solution();

  return 0;
}
