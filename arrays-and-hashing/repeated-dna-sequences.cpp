/**
 * 1. Hashing and Sliding Window - O(n)
 *      Maintain window of size 10 and check if that window has already occured
 *      Track window and its frequency in hashmap and push to ans if frequency is 2
 *        so its always pushed once
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
  int n = s.size();

  unordered_map<string, int> occurred;
  string window = "";
  vector<string> ans;

  for (int i = 0; i < 9 && i < n; i++) {
    window += s[i];
  }

  for (int i = 9; i < n; i++) {
    window += s[i];

    occurred[window]++;

    if (occurred[window] == 2) {
      ans.push_back(window);
    }

    window = window.substr(1, 9);
  }

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  vector<string> ans = findRepeatedDnaSequences(s);

  for (string a: ans) {
    cout << a << " ";
  }
  cout << endl;
}

int main()
{
  solution();

  return 0;
}
