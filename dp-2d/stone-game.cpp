#include <bits/stdc++.h>

using namespace std;

string getKey(int l, int r, bool isAliceTurn)
{
  return to_string(l) + "," + to_string(r) + "," + to_string(isAliceTurn);
}

bool stoneGame(vector<int>& piles, int l, int r, bool isAliceTurn, unordered_map<string, bool>& dp)
{
  int len = r - l + 1;
  if (len <= 2) {
    return isAliceTurn;
  }

  string key = getKey(l, r, isAliceTurn);

  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  bool leftRemove = stoneGame(piles, l + 1, r, !isAliceTurn, dp);
  bool rightRemove = stoneGame(piles, l, r - 1, !isAliceTurn, dp);

  dp[key] = leftRemove || rightRemove;

  return dp[key];
}

bool stoneGame(vector<int>& piles)
{
  int n = piles.size();

  unordered_map<string, bool> dp;

  return stoneGame(piles, 0, n - 1, true, dp);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> piles(n);
  for (int i = 0; i < n; i++) {
    cin >> piles[i];
  }

  cout << stoneGame(piles) << endl;
}

int main()
{
  solution();

  return 0;
}
