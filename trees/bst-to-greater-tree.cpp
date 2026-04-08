#include <bits/stdc++.h>
#include "tree-node.h"

using namespace std;

TreeNode* convertBST(TreeNode* root, int& currRunningVal)
{
  if (root == nullptr) {
    return nullptr;
  }

  root->right = convertBST(root->right, currRunningVal);

  currRunningVal += root->val;
  root->val = currRunningVal;

  root->left = convertBST(root->left, currRunningVal);

  return root;

}

TreeNode* convertBST(TreeNode* root)
{
  int currRunningVal = 0;

  root = convertBST(root, currRunningVal);

  return root;
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
