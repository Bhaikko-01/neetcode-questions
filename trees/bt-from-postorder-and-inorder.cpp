#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

TreeNode* buildTree(vector<int>& inorder, int inS, int inE, vector<int>& postorder, int poS, int poE)
{
  if (inS > inE || poS > poE) {
    return nullptr;
  }

  if (poS == poE) {
    TreeNode* root = new TreeNode(postorder[poE]);
    return root;
  }

  TreeNode* root = new TreeNode(postorder[poE]);

  int index = -1;
  for (int i = inS; i <= inE; i++) {
    if (inorder[i] == root->val) {
      index = i;
      break;
    }
  }

  int leftInS = inS;
  int leftInE = index - 1;
  int rightInS = index + 1;
  int rightInE = inE;

  int count = inE - index;

  int leftPoS = poS;
  int leftPoE = poE - count - 1;
  int rightPoS = leftPoE + 1;
  int rightPoE = poE - 1;

  root->left = buildTree(inorder, leftInS, leftInE, postorder, leftPoS, leftPoE);
  root->right = buildTree(inorder, rightInS, rightInE, postorder, rightPoS, rightPoE);

  return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
  int n = inorder.size();
  int m = postorder.size();

  return buildTree(inorder, 0, n - 1, postorder, 0, m - 1);
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
