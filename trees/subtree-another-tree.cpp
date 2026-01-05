/**
 * 1. Brute Force O(n * m) - ONLY WAY TO SOLVE THIS
 *      Run isSameTree for every root. Detect subtree using this
 *        isSameTree would match two trees values and return true if equal
 *      Repeat for left and right if isSameTree returns false for root
 *        call isSubTree on left and right with subRoot
*/
#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q)
{
  if (p == nullptr && q == nullptr) {
    return true;
  }

  if (p && q && p->val == q->val) {
    bool isLeftSameTree = isSameTree(p->left, q->left);
    bool isRightSameTree = isSameTree(p->right, q->right);

    return isLeftSameTree && isRightSameTree;
  }

  return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot)
{
  if (!subRoot) {
    return true;
  }

  if (!root) {
    return false;
  }

  bool isRootSubTree = isSameTree(root, subRoot);

  if (isRootSubTree) {
    return true;
  }

  bool isLeftSubtree = isSubtree(root->left, subRoot);
  bool isRightSubtree = isSubtree(root->right, subRoot);

  return isLeftSubtree || isRightSubtree;
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
