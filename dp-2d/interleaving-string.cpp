#include <bits/stdc++.h>

using namespace std;

string getKey(int x, int y)
{
  return to_string(x) + "," + to_string(y);
}

bool isInterleave(string s1, string s2, string s3, int s1Index, int s2Index, unordered_map<string, bool>& occured)
{
  int x = s1.size(),
      y = s2.size();

  string key = getKey(s1Index, s2Index);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (s1Index == x && s2Index == y) {
    return true;
  }

  if (s1Index > x || s2Index > y) {
    return false;
  }

  int s3Index = s1Index + s2Index;

  bool considerFirst = false;
  if (s1[s1Index] == s3[s3Index]) {
    considerFirst = isInterleave(s1, s2, s3, s1Index + 1, s2Index, occured);
  }

  bool considerSecond = false;
  if (s2[s2Index] == s3[s3Index]) {
    considerSecond = isInterleave(s1, s2, s3, s1Index, s2Index + 1, occured);
  }

  occured[key] = considerFirst || considerSecond;

  return considerFirst || considerSecond;
}

bool isInterleave(string s1, string s2, string s3)
{
  int x = s1.size(),
    y = s2.size(),
    z = s3.size();

  if (x + y != z) {
    return false;
  }

  unordered_map<string, bool> occured;

  return isInterleave(s1, s2, s3, 0, 0, occured);
}

bool isInterleaveDp(string s1, string s2, string s3)
{
  int x = s1.size(),
      y = s2.size(),
      z = s3.size();

  if (x + y != z) {
    return false;
  }

  vector<vector<bool>> dp(x + 1, vector<bool>(y + 1, false));
  dp[x][y] = true;

  // ! These are calculated as we have
  // ! (s1Index > x || s2Index > y) condition inrecursion
  // ! which means, we cann use the index which is at end
  // ! hence populate DP using current index only
  for (int i = x - 1; i >= 0; i--) {
    dp[i][y] = s3[i + y] == s1[i] && dp[i + 1][y];
  }
  for (int i = y - 1; i >= 0; i--) {
    dp[x][i] = s3[x + i] == s2[i] && dp[x][i + 1];
  }

  for (int i = x - 1; i >= 0; i--) {
    for (int j = y - 1; j >= 0; j--) {
      int s3Index = i + j;

      bool considerFirst = false;
      if (s1[i] == s3[s3Index]) {
        considerFirst = dp[i + 1][j];
      }

      bool considerSecond = false;
      if (s2[j] == s3[s3Index]) {
        considerSecond = dp[i][j + 1];
      }

      dp[i][j] = considerFirst || considerSecond;
    }
  }

  return dp[0][0];
}

void solution()
{
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  cout << isInterleaveDp(s1, s2, s3) << endl;
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
