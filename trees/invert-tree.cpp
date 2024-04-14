/**
 * 1. Recursively Postorder update pointers - O(n) Postorder
 *      At every point, get leftInvertedTree and rightInvertedTree
 *      Swap by considering nullptr
 *      Return current root with updated pointers
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

TreeNode* invertTree(TreeNode* root)
{
  if (root == nullptr) {
    return root;
  }

  TreeNode* leftInvertedTree = invertTree(root->left);
  TreeNode* rightInvertedTree = invertTree(root->right);

  if (leftInvertedTree && rightInvertedTree) {
    root->left = rightInvertedTree;
    root->right = leftInvertedTree;
  } else if (leftInvertedTree) {
    root->right = leftInvertedTree;
    root->left = nullptr;
  } else if (rightInvertedTree) {
    root->left = rightInvertedTree;
    root->right = nullptr;
  }

  return root;
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
