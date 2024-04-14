/**
 * 1. Recursive Postorder - O(n)
 *      Since Decision is based on depth,
 *        depth is calculated for every root and
 *        recursion-global variable is maintained for determining balanced tree
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

int isBalanced(TreeNode* root, bool& isBalancedTree)
{
  if (!isBalancedTree) {
    return false;
  }

  if (root == nullptr) {
    return 0;
  }

  int leftDepth = isBalanced(root->left, isBalancedTree);
  int rightDepth = isBalanced(root->right, isBalancedTree);

  isBalancedTree = isBalancedTree && abs(leftDepth - rightDepth) <= 1;

  return 1 + max(leftDepth, rightDepth);
}

bool isBalanced(TreeNode* root)
{
  bool isBalancedTree = true;

  isBalanced(root, isBalancedTree);

  return isBalancedTree;
}

void solution()
{
  
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
