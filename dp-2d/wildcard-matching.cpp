#include <bits/stdc++.h>

using namespace std;

string getKey(int x, int y)
{
  return to_string(x) + "," + to_string(y);
}

bool isMatch(string& s, string& p, int sIndex, int pIndex, unordered_map<string, int>& dp)
{
  int n = s.size();
  int m = p.size();

  if (sIndex >= n && pIndex >= m) {
    return true;
  }

  if (pIndex >= m) {
    return false;
  }

  if (sIndex >= n) {
    for (int i = pIndex; i < m; i++) {
      if (p[i] == '*') {
        continue;
      }

      return false;
    }

    return true;
  }

  string key = getKey(sIndex, pIndex);

  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  if (p[pIndex] == '*') {
    bool ignore = isMatch(s, p, sIndex, pIndex + 1, dp);
    bool consider = isMatch(s, p, sIndex + 1, pIndex, dp);

    dp[key] = ignore || consider;

    return dp[key];
  }

  if (p[pIndex] == '?' || s[sIndex] == p[pIndex]) {
    dp[key] = isMatch(s, p, sIndex + 1, pIndex + 1, dp);
    return dp[key];
  }

  dp[key] = false;
  return dp[key];
}

bool isMatch(string s, string p)
{
  unordered_map<string, int> dp;

  return isMatch(s, p, 0, 0, dp);
}

void solution()
{
  string s, p;
  cin >> s >> p;

  cout << isMatch(s, p) << endl;
}

int main()
{
  solution();

  return 0;
}
