/**
 * 1. Brute Force O(n^2)
 *      For each root, check
 *        It is greater than all nodes in left subtree
 *        It is greater than all nodes in right subtree
 *      Repeat this check for all nodes
 * 2. Recursive Preorder O(n) [T + S]
 *      Maintain possible maxAllowed and minAllowed allowed at each root
 *        root must be between maxAllowed and minAllowed
 *      Check if both left and right subtree are BST
 *        If yes, traverse left subtree with root as its maxAllowed
 *                traverse right subtree with root as it minAllowed
 *        Else not a BST
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

typedef long long ll;

bool isValidBST(TreeNode* root, ll possibleMinVal, ll possibleMaxVal)
{
  if (root == nullptr) {
    return true;
  }

  if (root->val < possibleMaxVal && root->val > possibleMinVal) {
    return isValidBST(root->left, possibleMinVal, (ll)root->val) &&
           isValidBST(root->right, (ll)root->val, possibleMaxVal);
  }

  return false;
}

bool isValidBST(TreeNode* root)
{
  return isValidBST(root, LLONG_MIN, LLONG_MAX);
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
