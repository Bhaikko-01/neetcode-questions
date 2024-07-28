/**
 * 1. Recursive solution - O(2^n)
 *    Take decision based on attaching opening and closing bracket
 *      Decision is taken by attaching to a running string
 *      totalSize of parenthesis will be (2 * n)
 *        opening bracket count and closing bracket count cannot be more than n
 *        closing bracket count cannot be more than opening bracket count
 *      if openingBracketCount == n AND closingBracketCount == n
 *        one parenthesis found
*/

#include <bits/stdc++.h>

using namespace std;

void generateParenthesis(int n, int openingCount, int closingCount, vector<string>& parenthesis, string currentParenthesis)
{
  if (openingCount > n || closingCount > n) {
    return;
  }

  if (closingCount > openingCount) {
    return;
  }

  if (openingCount == n && closingCount == n) {
    parenthesis.push_back(currentParenthesis);
    return;
  }

  generateParenthesis(n, openingCount + 1, closingCount, parenthesis, currentParenthesis + "(");
  generateParenthesis(n, openingCount, closingCount + 1, parenthesis, currentParenthesis + ")");
}

vector<string> generateParenthesis(int n)
{
  vector<string> ans;

  generateParenthesis(n, 0, 0, ans, "");

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<string> ans = generateParenthesis(n);

  for (string x: ans) {
    cout << x << " ";
  }

  cout << endl;
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
