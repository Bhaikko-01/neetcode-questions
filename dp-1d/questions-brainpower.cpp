#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long mostPoints(vector<vector<int>>& questions, int currIndex, vector<ll>& dp)
{
  int n = questions.size();

  if (currIndex >= n) {
    return 0;
  }

  if (dp[currIndex] != -1) {
    return dp[currIndex];
  }

  ll solvingCurr = mostPoints(questions, currIndex + questions[currIndex][1] + 1, dp) + questions[currIndex][0];
  ll notSolvingCurr = mostPoints(questions, currIndex + 1, dp);

  dp[currIndex] = max(solvingCurr, notSolvingCurr);

  return dp[currIndex];
}

long long mostPoints(vector<vector<int>>& questions)
{
  int n = questions.size();

  vector<ll> dp(n + 1, -1);

  return mostPoints(questions, 0, dp);
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> questions(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> questions[i][0] >> questions[i][1];
  }

  cout << mostPoints(questions) << endl;
}

int main()
{
  solution();

  return 0;
}
