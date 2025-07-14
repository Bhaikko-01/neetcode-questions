/**
 * Similar to 1D house robber DP problem
 * 1. Recursion - O(2^n)
 *      If current root is picked then skip left and right directly
 *        and call recursion on rob on children on left and right
 *      Otherwise simply call on left and right
 *      Ans is max of includingCurr and excludingCurr
 * 2. Memoize - O(n)
 *      Memoize based on root address and return if it is already computed
 */

#include <bits/stdc++.h>
#include "tree-node.h"

using namespace std;

int rob(TreeNode* root, unordered_map<TreeNode*, int>& cache)
{
  if (root == nullptr) {
    return 0;
  }

  if (cache.find(root) != cache.end()) {
    return cache[root];
  }

  int includingCurr = root->val;
  if (root->left) {
    includingCurr += rob(root->left->left, cache);
    includingCurr += rob(root->left->right, cache);
  }

  if (root->right) {
    includingCurr += rob(root->right->left, cache);
    includingCurr += rob(root->right->right, cache);
  }

  int excludingCurr = rob(root->left, cache) + rob(root->right, cache);

  cache[root] = max(includingCurr, excludingCurr);

  return cache[root];
}

int rob(TreeNode* root)
{
  unordered_map<TreeNode*, int> cache;

  return rob(root, cache);
}

void solution()
{
  TreeNode* tree = new TreeNode(
    3,
    new TreeNode(
      2,
      nullptr,
      new TreeNode(3)
    ),
    new TreeNode(
      3,
      nullptr,
      new TreeNode(1)
    )
  );

  cout << rob(tree) << endl;
}

int main()
{
  solution();

  return 0;
}
