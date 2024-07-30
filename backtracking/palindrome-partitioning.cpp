/**
 * 1. Backtracking - O(n*2^n)
 *      Partition string at each iteration from currIndex to (n - 1)
 *        partition of increasing size are done, for eg 1, 2, 3 till currIndex + size <= n
 *        Call recursion on (currIndex + size) index
 *      If curr left parition is palindrone, then only subsequent calls are made for paritions
 *        left parition is pushed to running paritions
 *        after each call, we pop and consider next leftParition
 *      Else
 *        skip that recursion call
 * Time Complexity:
 *    At each level, n^2 work is done
 *      Generating n paritions for a given string - O(n)
 *      Checking palindrome, Copying parition array, pushing and poping - O(n)
 *    Therefore total operations = n*(2^1 + 2^2 + 2^3 -- 2^n) = O(n^2*2^n)
 *    Depth of tree is n therefore O(n*2^n)
 *
 *
 * Time complexity on internet is O(n*2^n) when 2^n partitions are created, each parition will have n paritions
 *  but checking Palindrome is not considered of time O(n)
*/
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
  int l = 0, r = s.size() - 1;

  while (l <= r) {
    if (s[l] != s[r]) {
      return false;
    }

    l++;
    r--;
  }

  return true;
}

void partition(string s, int currIndex, vector<string> partitions, vector<vector<string>>& answers)
{
  int n = s.size();

  if (currIndex == n) {
    answers.push_back(partitions);
    return;
  }

  if (currIndex > n) {
    return;
  }

  for (int size = 1; size + currIndex <= n; size++) {
    string partitionSubstring = s.substr(currIndex, size);

    if (isPalindrome(partitionSubstring)) {
      partitions.push_back(partitionSubstring);

      partition(s, currIndex + size, partitions, answers);

      partitions.pop_back();
    }
  }
}

vector<vector<string>> partition(string s)
{
  int n = s.size();
  vector<string> partitions;
  vector<vector<string>> ans;

  partition(s, 0, partitions, ans);

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  vector<vector<string>> ans = partition(s);

  for (auto x: ans) {
    for (string y: x) {
      cout << y << " ";
    }
    cout << endl;
  }
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
