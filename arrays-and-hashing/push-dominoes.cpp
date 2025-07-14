/**
 * 1. Brute Force - O(n^2)
 *      On Every index, find closet falling domino that will reach it.
 *      Search on right to find 'L' and get its index
 *        If 'L' is not found or 'R' is found before L then current index will not be affected by it
 *      Search on left to find 'R' and get its index
 *        If 'R' is not found or 'L' is found before R then current index will not be affected by it
 *      Using both index,
 *        If rIndex == lIndex -> No effect
 *        Else, closet index will bring the current domino down first
 * 
 * 2. Hashing - O(n) [T + S]
 *      Cache closet 'L' and 'R' occurences for each index by preprocessing
 *        Keep track of closet index occured for current index and assign that
 *          If opposite dominos encountered then reset closet index
 *      After preprocessing, algo remains same as brute force based on comparison
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

// 1.
pp getLRIndexes(string& dominoes, int index)
{
  pp indexes = { -1, -1 };
  int n = dominoes.size();

  for (int i = index - 1; i >= 0; i--) {
    if (dominoes[i] == 'L') {
      break;
    }

    if (dominoes[i] == 'R') {
      indexes.first = i;
      break;
    }
  }
  
  for (int i = index + 1; i < n; i++) {
    if (dominoes[i] == 'R') {
      break;
    }

    if (dominoes[i] == 'L') {
      indexes.second = i;
      break;
    }
  }

  return indexes;
}

// 2.
vector<int> getLIndexes(string& dominoes)
{
  int n = dominoes.size();
  vector<int> indexes(n, -1);

  int currLeftIndex = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (dominoes[i] == 'L') {
      currLeftIndex = i;
    }

    if (dominoes[i] == 'R') {
      currLeftIndex = -1;
    }

    indexes[i] = currLeftIndex;
  }

  return indexes;
}

// 2.
vector<int> getRIndexes(string& dominoes)
{
  int n = dominoes.size();
  vector<int> indexes(n, -1);

  int currRightIndex = -1;
  for (int i = 0; i < n; i++) {
    if (dominoes[i] == 'R') {
      currRightIndex = i;
    }

    if (dominoes[i] == 'L') {
      currRightIndex = -1;
    }

    indexes[i] = currRightIndex;
  }

  return indexes;
}

string pushDominoes(string dominoes)
{
  int n = dominoes.size();
  string ans = string(dominoes);

  vector<int> leftRIndexes = getRIndexes(dominoes);
  vector<int> rightLIndexes = getLIndexes(dominoes);

  for (int i = 0; i < n; i++) {
    if (dominoes[i] == '.') {
      // 1.
      // pp indexes = getLRIndexes(dominoes, i);
      // int leftRIndex = indexes.first;
      // int rightLIndex = indexes.second;

      // 2.
      int leftRIndex = leftRIndexes[i];
      int rightLIndex = rightLIndexes[i];

      if (leftRIndex == -1 && rightLIndex == -1) {
        continue;
      } else if (leftRIndex == -1 && rightLIndex != -1) {
        ans[i] = 'L';
      } else if (leftRIndex != -1 && rightLIndex == -1) {
        ans[i] = 'R';
      } else {
        int lDis = i - leftRIndex;
        int rDis = rightLIndex - i;


        if (lDis == rDis) {
          continue;
        } else if (lDis > rDis) {
          ans[i] = 'L';
        } else {
          ans[i] = 'R';
        }
      }
    }
  }

  return ans;
}

void solution()
{
  string dominoes;
  cin >> dominoes;

  cout << pushDominoes(dominoes) << endl;
}

int main()
{
  solution();

  return 0;
}
