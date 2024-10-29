/**
 * 1. Prefix sums - O(n)
 *      Since each robot can only turn once to bottom, robot1 all possible paths are calculated
 *        using PrefixSum of both rows
 *      For every down movement, robot2 has two possiblities
 *        Pick row1 remaining
 *        Pick row2 remaining
 *      Since robot2 wants to maximize, we pick max of row1Remaining and row2Remaining
 *      Since robot1 wants to minimize robot2, ans = min(ans, robot2)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long gridGame(vector<vector<int>>& grid)
{
  int n = grid[0].size();

  vector<ll> prefixSumRow1(n),
             prefixSumRow2(n);

  ll totalSumRow1 = 0,
     totalSumRow2 = 0;

  for (int i = 0; i < n; i++) {
    totalSumRow1 += grid[0][i];
    totalSumRow2 += grid[1][i];

    prefixSumRow1[i] = totalSumRow1;
    prefixSumRow2[i] = totalSumRow2;
  }

  ll ans = LLONG_MAX;
  ll diff = 0;

  for (int goDownIndex = 0; goDownIndex < n; goDownIndex++) {
    ll firstRobotPath = prefixSumRow1[goDownIndex] + totalSumRow2;

    if (goDownIndex - 1 >= 0) {
      firstRobotPath -= prefixSumRow2[goDownIndex - 1];
    }

    ll secondRobotFirstChoice = 0;
    if (goDownIndex - 1 >= 0) {
      secondRobotFirstChoice = prefixSumRow2[goDownIndex - 1];
    }

    ll secondRobotSecondChoice = totalSumRow1 - prefixSumRow1[goDownIndex];
    ll secondRobotPath = max(secondRobotFirstChoice, secondRobotSecondChoice);

    ans = min(ans, secondRobotPath);
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> grid(2, vector<int>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  cout << gridGame(grid) << endl;
}

int main()
{
  solution();

  return 0;
}
