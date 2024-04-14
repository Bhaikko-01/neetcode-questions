#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

// Preorder
bool isSameTree(TreeNode* p, TreeNode* q)
{
  if (p == nullptr && q == nullptr) {
    return true;
  }

  if (p == nullptr && q != nullptr || p != nullptr && q == nullptr) {
    return false;
  }

  if (p->val != q->val) {
    return false;
  }

  bool isLeftSameTree = isSameTree(p->left, q->left);
  bool isRightSameTree = isSameTree(p->right, q->right);

  return isLeftSameTree && isRightSameTree;
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
