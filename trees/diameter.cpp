/**
 * 1. Recursive Postorder O(n)
 *      Diameter depends on depth of left subtree and right subtree
 *      Depth at each root will be calculated and
 *        maxDiameter got till now will be ans
 *        Passed as reference in whole recursion
 *      Need to pass as reference as we need whole tree context to determine diameter
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

int diameterOfBinaryTree(TreeNode* root, int& maxDiameter)
{
  if (root == nullptr) {
    return 0;
  }

  int leftDepth = diameterOfBinaryTree(root->left, maxDiameter);
  int rightDepth = diameterOfBinaryTree(root->right, maxDiameter);

  int currDiameter = leftDepth + rightDepth;
  maxDiameter = max(maxDiameter, currDiameter);

  return 1 + max(leftDepth, rightDepth);
}

int diameterOfBinaryTree(TreeNode* root)
{
  int diameter = INT_MIN;

  diameterOfBinaryTree(root, diameter);

  return diameter;
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
