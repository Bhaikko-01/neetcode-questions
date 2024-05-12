/**
 * 1. Greedy - O(n) [T]
 *      Just need to check if merge to get target is possible or not, no need to get ways to merge
 *      Check whitelisted triplets where all elements of that are less than equal to target
 *      Make sure target elements exist in whitelisted triplets as well
 *      If triplet with exact same match with target found then that is ans as well
*/

#include <bits/stdc++.h>

using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target)
{
  int n = triplets.size();

  bool xFound = false,
       yFound = false,
       zFound = false;

  for (vector<int> triplet: triplets) {
    // ! This can be written as triplet == target as vectors are compared lexo-graphically
    if (triplet[0] == target[0] && triplet[1] == target[1] && triplet[2] == target[2]) {
      return true;
    }

    if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
      continue;
    }

    if (triplet[0] == target[0]) {
      xFound = true;
    }

    if (triplet[1] == target[1]) {
      yFound = true;
    }

    if (triplet[2] == target[2]) {
      zFound = true;
    }
  }

  return xFound && yFound && zFound;
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> triplets(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> triplets[i][0] >> triplets[i][1] >> triplets[i][2];
  }

  vector<int> target(3);
  cin >> target[0] >> target[1] >> target[2];

  cout << mergeTriplets(triplets, target) << endl;
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
