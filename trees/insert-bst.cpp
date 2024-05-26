#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val)
{
  if (root == nullptr) {
    TreeNode* newNode = new TreeNode(val);

    return newNode;
  }

  if (val < root->val) {
    root->left = insertIntoBST(root->left, val);
  } else {
    root->right = insertIntoBST(root->right, val);
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
