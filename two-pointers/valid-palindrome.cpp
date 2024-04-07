#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
  int l = 0, r = s.length() - 1;

  while (l < r) {
    if (!isalnum(s[l])) {
      l++;
    } else if (!isalnum(s[r])) {
      r--;
    } else {
      if (tolower(s[l]) != tolower(s[r])) {
        return false;
      }

      l++;
      r--;
    }
  }

  return true;
}

void solution()
{
  string word;
  getline(cin, word);

  cout << isPalindrome(word) << endl;
}

int main()
{
  solution();

  return 0;
}
