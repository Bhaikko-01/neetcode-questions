/**
 * How deletion works in BST
 *  1. If currNode is leaf, simply return null
 *  2. IF currNode has one child, return that child
 *  3. If currNode has both child
 *      Find inorder successor of curr element
 *      Swap values with inorder successor and currNode
 *      delete currNode value in right subtree and assign that subtree to root->right
 *        root->right = deleteNode(root->right, key)
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

TreeNode* deleteNode(TreeNode* root, int key)
{
  if (root == nullptr) {
    return nullptr;
  }

  if (root->val == key) {
    if (!root->left && !root->right) {
      delete root;

      return nullptr;
    } else if (!root->left) {
      TreeNode* rightNode = root->right;

      delete root;

      return rightNode;
    } else if (!root->right) {
      TreeNode* leftNode = root->left;

      delete root;

      return leftNode;
    } else {
      // Find inorder successor

      TreeNode* currNode = root->right;

      while (currNode->left != nullptr) {
        currNode = currNode->left;
      }

      swap(currNode->val, root->val);

      root->right = deleteNode(root->right, key);

      return root;
    }
  }

  if (key <= root->val) {
    root->left = deleteNode(root->left, key);
  } else {
    root->right = deleteNode(root->right, key);
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
