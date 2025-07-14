/**
 * 1. Sliding Window
 *      Maintain window of size p and match occurence of substring of sWindow and pOcc
 */

#include <bits/stdc++.h>

using namespace std;

bool isAnagram(unordered_map<char, int>& sOcc, unordered_map<char, int>& pOcc)
{
  for (char x = 'a'; x <= 'z'; x++) {
    if (sOcc[x] != pOcc[x]) {
      return false;
    }
  }

  return true;
}

vector<int> findAnagrams(string s, string p)
{
  unordered_map<char, int> pOcc, sOcc;

  for (char a: p) {
    pOcc[a]++;
  }

  int n = s.size(),
      m = p.size();

  int l = 0,
      r = m - 1;

  vector<int> ans;

  for (int i = 0; i < m - 1; i++) {
    sOcc[s[i]]++;
  }

  for (r; r < n; r++) {
    sOcc[s[r]]++;

    bool isCurrWindowAnagram = isAnagram(sOcc, pOcc);

    if (isCurrWindowAnagram) {
      ans.push_back(l);
    }

    sOcc[s[l]]--;
    l++;
  }

  return ans;
}

void solution()
{
  string s, p;
  cin >> s >> p;

  vector<int> ans = findAnagrams(s, p);

  for (int x: ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main()
{
  solution();

  return 0;
}
