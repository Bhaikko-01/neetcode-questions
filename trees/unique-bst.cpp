/**
 * 1. Recursion and DP - O(n)
 *      For each value as root, get how many subtrees possible on left and right side
 *        Current element will not considered when finding subTrees
 *        Above will be a recursive function
 *      Sum of product of leftTrees and rightTrees will be final number of trees
 */

#include <bits/stdc++.h>

using namespace std;

int numTrees(int n, unordered_map<int, int>& cache)
{
  if (n == 1) {
    return 1;
  }

  if (cache.find(n) != cache.end()) {
    return cache[n];
  }

  // * Considering edge values as root.
  // * Left extreme will not have left subtree
  // * Right extreme will not have right subtree
  int totalTrees = 2 * numTrees(n - 1, cache);

  for (int i = 2; i < n; i++) {
    int leftPossibleTrees = numTrees(i - 1, cache);
    int rightPossibleTrees = numTrees(n - i, cache);

    totalTrees += (leftPossibleTrees * rightPossibleTrees);
  }

  cache[n] = totalTrees;

  return cache[n];
}

int numTrees(int n)
{
  unordered_map<int, int> cache;

  return numTrees(n, cache);
}

void solution()
{
  int n;
  cin >> n;

  cout << numTrees(n) << endl;
}

int main()
{
  solution();

  return 0;
}
