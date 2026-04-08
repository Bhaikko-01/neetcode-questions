#include <bits/stdc++.h>
#include "tree-node.h"

using namespace std;

void fillDepthSum(TreeNode* root, int currDepth, unordered_map<int, int>& depthSum)
{
  if (root == nullptr) {
    return;
  }

  depthSum[currDepth] += root->val;

  fillDepthSum(root->left, currDepth + 1, depthSum);
  fillDepthSum(root->right, currDepth + 1, depthSum);
}

void replaceValueInTree(TreeNode* root, int depth, unordered_map<int, int>& depthSum)
{
  if (root == nullptr) {
    return;
  }

  int leftChildVal = root->left ? root->left->val : 0;
  int rightChildVal = root->right ? root->right->val : 0;

  int valueToUpdate = depthSum[depth + 1] - leftChildVal - rightChildVal;

  if (root->left) {
    root->left->val = valueToUpdate;
  }

  if (root->right) {
    root->right->val = valueToUpdate;
  }

  replaceValueInTree(root->left, depth + 1, depthSum);
  replaceValueInTree(root->right, depth + 1, depthSum);
}

TreeNode* replaceValueInTree(TreeNode* root)
{
  unordered_map<int, int> depthSum;

  fillDepthSum(root, 0, depthSum);
  replaceValueInTree(root, 0, depthSum);

  root->val = 0;

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
