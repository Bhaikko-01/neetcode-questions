#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> precedenceMapping = {
  {"+", 10},
  {"-", 10},
  {"*", 20},
  {"/", 20}
};

bool isOperator(char x) {
  return (
    x == '+' ||
    x == '-' ||
    x == '*' ||
    x == '/'
  );
}

string evaluateExpression(const string& first, const string& second, const string& op)
{
  if (op == "+") {
    return to_string(stoi(first) + stoi(second));
  }

  if (op == "-") {
    return to_string(stoi(first) - stoi(second));
  }

  if (op == "*") {
    return to_string(stoi(first) * stoi(second));
  }

  if (op == "/") {
    return to_string(stoi(first) / stoi(second));
  }

  return "";
}

int calculate(string s)
{
  string currNumber = "";

  stack<string> operandStack, operatorStack;

  for (char x: s) {
    if (x == ' ') {
      continue;
    }

    if (isOperator(x)) {
      operandStack.push(currNumber);
      currNumber = "";

      string currOperator = string(1, x);

      if (operatorStack.empty()) {
        operatorStack.push(currOperator);
      } else {
        while (
          !operatorStack.empty() && (
            precedenceMapping[currOperator] <=
            precedenceMapping[operatorStack.top()]
          )
        ) {
          string second    = operandStack.top(); operandStack.pop();
          string first   = operandStack.top(); operandStack.pop();
          string op       = operatorStack.top(); operatorStack.pop();

          string evaluatedExp = evaluateExpression(first, second, op);

          operandStack.push(evaluatedExp);
        }

        operatorStack.push(currOperator);
      }
    } else if (isdigit(x)) {
      currNumber += string(1, x);
    }
  }

  operandStack.push(currNumber);

  while (!operatorStack.empty()) {
    string second    = operandStack.top(); operandStack.pop();
    string first   = operandStack.top(); operandStack.pop();
    string op       = operatorStack.top(); operatorStack.pop();

    string evaluatedExp = evaluateExpression(first, second, op);

    operandStack.push(evaluatedExp);
  }

  return stoi(operandStack.top());
}

void solution()
{
  string s = "3+5 / 2 ";
  cin >> s;

  cout << calculate(s) << endl;
}

int main()
{
  solution();

  return 0;
}
