#include <bits/stdc++.h>

using namespace std;

vector<int> getCharOccurence(string& str)
{
  vector<int> occurence(2, 0);

  for (char x: str) {
    if (x == '0') {
      occurence[0]++;
    } else {
      occurence[1]++;
    }
  }

  return occurence;
}

int findMaxForm(
  vector<string>& strs,
  int currIndex, int usedM, int usedN, int m, int n,
  vector<vector<vector<int>>>& dp,
  unordered_map<string, vector<int>>& zeroOneOccurences
) {
  int size = strs.size();

  if (currIndex >= size) {
    return 0;
  }

  if (usedM > m || usedN > n) {
    return 0;
  }

  if (dp[currIndex][usedM][usedN] != -1) {
    return dp[currIndex][usedM][usedN];
  }

  vector<int> currCharOccurence = zeroOneOccurences[strs[currIndex]];
  int curr0Use = currCharOccurence[0];
  int curr1Use = currCharOccurence[1];

  int includeCurr = 0;
  if (usedM + curr0Use <= m && usedN + curr1Use <= n) {
    includeCurr = findMaxForm(strs, currIndex + 1, usedM + curr0Use, usedN + curr1Use, m, n, dp, zeroOneOccurences) + 1;
  }

  int excludeCurr = findMaxForm(strs, currIndex + 1, usedM, usedN, m, n, dp, zeroOneOccurences);

  dp[currIndex][usedM][usedN] = max(includeCurr, excludeCurr);

  return dp[currIndex][usedM][usedN];
}

int findMaxForm(vector<string>& strs, int m, int n)
{
  int size = strs.size();

  vector<vector<vector<int>>> dp(size, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
  unordered_map<string, vector<int>> zeroOneOccurences;

  for (string str: strs) {
    zeroOneOccurences[str] = getCharOccurence(str);
  }

  return findMaxForm(strs, 0, 0, 0, m, n, dp, zeroOneOccurences);
}

void solution()
{
  int size;
  cin >> size;

  vector<string> strs(size);
  for (int i = 0; i < size; i++) {
    cin >> strs[i];
  }

  int m, n;
  cin >> m >> n;

  cout << findMaxForm(strs, m, n) << endl;
}

int main()
{
  solution();

  return 0;
}
