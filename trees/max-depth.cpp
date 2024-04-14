/**
 * 1. Recursive Postorder - O(n)
 *      Subproblem is getting depth of left Subtree and right subtree
 *      For a root, depth = 1 + max(leftDepth, rightDepth)
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

int maxDepth(TreeNode* root)
{
  if (root == nullptr) {
    return 0;
  }

  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);

  return 1 + max(leftDepth, rightDepth);
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
