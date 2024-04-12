/**
 * 1. Use stack to evaluate - O(n) - [T + S]
 *    if operand encountered, evaluate using top two elements
 *      topmost will be second operator and next to it will be first.
 *      push their result to stack
 *    if operand encountered, simply push to stack
 *    ans is at top of stack in end
*/

#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens)
{
  stack<int> evaluationStack;

  for (string o: tokens) {
    if (o == "+") {
      int second = evaluationStack.top(); evaluationStack.pop();
      int first = evaluationStack.top(); evaluationStack.pop();

      evaluationStack.push(first + second);
    } else if (o == "-") {
      int second = evaluationStack.top(); evaluationStack.pop();
      int first = evaluationStack.top(); evaluationStack.pop();

      evaluationStack.push(first - second);
    } else if (o == "*") {
      int second = evaluationStack.top(); evaluationStack.pop();
      int first = evaluationStack.top(); evaluationStack.pop();

      evaluationStack.push(first * second);
    } else if (o == "/") {
      int second = evaluationStack.top(); evaluationStack.pop();
      int first = evaluationStack.top(); evaluationStack.pop();

      evaluationStack.push(first / second);
    } else {
      evaluationStack.push(stoi(o));
    }
  }

  return evaluationStack.top();
}

void solution()
{
  int n;
  cin >> n;

  vector<string> tokens(n);
  for (int i = 0; i < n; i++) {
    cin >> tokens[i];
  }

  cout << evalRPN(tokens) << endl;
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
