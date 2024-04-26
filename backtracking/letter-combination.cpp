/**
 * 1. Backtracking - O(4^n)
 *      Maintain current combination and append all possible key of current number
 *        one by one and call recursion on next index
 *    Time Complexity
 *      At each iteration, we do O(1) work and
 *        total number of iterations = 4^1 + 4^2 + 4^3 + --- 4^n = O(4^n)
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, string> phoneMapping = {
  {'2', "abc"},
  {'3', "def"},
  {'4', "ghi"},
  {'5', "jkl"},
  {'6', "mno"},
  {'7', "pqrs"},
  {'8', "tuv"},
  {'9', "wxyz"},
};

void letterCombinations(string& digits, int index, string currCombination, vector<string>& ans)
{
  int n = digits.size();

  if (index == n) {
    ans.push_back(currCombination);
    return;
  }

  string key = phoneMapping[digits[index]];

  for (char x: key) {
    string newCombination = currCombination + x;
    letterCombinations(digits, index + 1, newCombination, ans);
  }
}

vector<string> letterCombinations(string digits)
{
  vector<string> ans;
  string currCombination = "";

  int n = digits.size();

  if (n == 0) {
    return ans;
  }

  letterCombinations(digits, 0, currCombination, ans);

  return ans;
}

void solution()
{
  string digits;
  cin >> digits;

  vector<string> combinations = letterCombinations(digits);

  for (string x: combinations) {
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
