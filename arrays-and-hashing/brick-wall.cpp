/**
 * 1. Brute Force - O(totalWidth * n)
 *      Consider every possible width and make cuts
 *        by iterating down every column
 *      Track which width is currently used by maintaing
 *        rowIndexes and consideredWidths
 * 2. Store Gap occurence - O(n * m)
 *      Store gap index occurence in a map by iterating at each row and column
 *        make sure not to include last column of each array
 *      Occurence of each gap tells us that cut went through without cutting brick
 *        hence numOfCuts = n - gapOccurence
 *      ans = min(numOfCuts, ans)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ! Brute Force
int leastBricksBrute(vector<vector<int>>& wall)
{
  int n = wall.size();

  int minCount = INT_MAX;

  vector<int> rowIndexes(n, 0);
  vector<int> consideredWidths(n, 0);

  int totalWidth = 0;
  for (int x: wall[0]) {
    totalWidth += x;
  }

  // ! Considering every possible cut and finding cuts by iterating each row
  for (int cut = 1; cut <= totalWidth - 1; cut++) {
    int currCuts = 0;

    for (int row = 0; row < n; row++) {
      int rowIndex = rowIndexes[row];

      int reach = wall[row][rowIndex] + consideredWidths[row];

      if (reach <= cut) {
        consideredWidths[row] += wall[row][rowIndex];
        rowIndexes[row]++;
      } else {
        currCuts++;
      }
    }

    minCount = min(minCount, currCuts);
  }

  return minCount;
}

int leastBricks(vector<vector<int>>& wall)
{
  int n = wall.size();

  unordered_map<int, ll> gapOccurences;

  for (int i = 0; i < n; i++) {
    int x = wall[i].size();

    ll currWidth = 0;

    for (int j = 0; j < x - 1; j++) {
      currWidth += (ll)wall[i][j];
      gapOccurences[currWidth]++;
    }
  }

  int minCuts = n;
  for (auto x: gapOccurences) {
    int cuts = n - x.second;
    minCuts = min(minCuts, cuts);
  }

  return minCuts;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> wall(n, vector<int>());

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;

    wall[i] = vector<int>(m);

    for (int j = 0; j < m; j++) {
      cin >> wall[i][j];
    }
  }

  cout << leastBricks(wall) << endl;
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

/*
  1
6
4 1 2 2 1
3 3 1 2
3 1 3 2
2 2 4
3 3 1 2
4 1 3 1 1
*/
