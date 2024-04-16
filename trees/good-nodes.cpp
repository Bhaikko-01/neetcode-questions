/**
 * 1. Recursive Preorder - O(n) [T + S]
 *      Maintain maxTillNow from root to each node
 *      If root >= maxTillNow, it is goodNode
 *        increase count and assign this value as maxTillNow
 *      Search in left and right subtree with maxTillNow
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

void goodNodes(TreeNode* root, int maxTillNow, int& count) {
  if (root == nullptr) {
    return;
  }

  if (root->val >= maxTillNow) {
    count++;
    maxTillNow = root->val;
  }

  if (root->left) {
    goodNodes(root->left, maxTillNow, count);
  }

  if (root->right) {
    goodNodes(root->right, maxTillNow, count);
  }
}

int goodNodes(TreeNode* root) {
  int count = 0;
  goodNodes(root, INT_MIN, count);

  return count;
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
