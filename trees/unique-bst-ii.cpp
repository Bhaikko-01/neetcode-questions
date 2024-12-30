/**
 * 1. Recursion and processing + DP - O(n^2)
 *      Similar to unique-bst-i problem,
 *        For each value as root, get subtrees possible on left and right side
 *          Combine those subtrees with curr value as root
 *          Always clone values when attaching
 *          For leftSubTree, no processing required for attaching
 *          For rightSubTree, increment each value by root value so they become greater than root
 *          Return all tree formed with current value
 *        Base-case: if n < 1 -> return [nullptr] # This case will occur when dealing with extremes
 *                   if n == 1 -> return [1]
 */

#include <bits/stdc++.h>
#include "tree-node.h"

using namespace std;

TreeNode* cloneWithIncrement(TreeNode* root, int val)
{
  if (root == nullptr) {
    return nullptr;
  }

  TreeNode* clonedRoot = new TreeNode(root->val + val);

  clonedRoot->left = cloneWithIncrement(root->left, val);
  clonedRoot->right = cloneWithIncrement(root->right, val);

  return clonedRoot;
}

vector<TreeNode*> generateTrees(int n, unordered_map<int, vector<TreeNode*>>& cache)
{
  if (n < 1) {
    return vector<TreeNode*>(1, nullptr);
  }

  if (n == 1) {
    return vector<TreeNode*>(1, new TreeNode(1));
  }

  if (cache.find(n) != cache.end()) {
    return cache[n];
  }

  vector<TreeNode*> currentTrees;

  for (int i = 1; i <= n; i++) {
    vector<TreeNode*> leftSubtrees = generateTrees(i - 1, cache);
    vector<TreeNode*> rightSubtrees = generateTrees(n - i, cache);

    for (TreeNode* leftSubTree: leftSubtrees) {
      for (TreeNode* rightSubTree: rightSubtrees) {
        TreeNode* newRoot = new TreeNode(i);

        newRoot->left = cloneWithIncrement(leftSubTree, 0);
        newRoot->right = cloneWithIncrement(rightSubTree, i);

        currentTrees.push_back(newRoot);
      }
    }
  }

  cache[n] = currentTrees;
  return cache[n];
}

vector<TreeNode*> generateTrees(int n)
{
  unordered_map<int, vector<TreeNode*>> cache;
  return generateTrees(n, cache);
}

void solution()
{
  int n;
  cin >> n;

  vector<TreeNode*> ans = generateTrees(n);

}

int main()
{
  solution();

  return 0;
}
