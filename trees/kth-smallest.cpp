#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

void kthSmallest(TreeNode* root, int k, int& i, int& val)
{
  if (root == nullptr) {
    return;
  }

  kthSmallest(root->left, k, i, val);

  i++;
  if (i == k) {
    val = root->val;
    return;
  }

  kthSmallest(root->right, k, i, val);
}

int kthSmallest(TreeNode* root, int k)
{
  int i = 0;
  int val = -1;

  kthSmallest(root, k, i, val);

  return val;
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
