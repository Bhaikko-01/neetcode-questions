/**
 * ------ FOR BST
 * 1. Use BST Tree order - O(logn)
 *      If p and q are in left, find LCA in left
 *      If p and q are in right, find LCA in right
 *      If p and q are in left and right subtree or vice versa,
 *        LCA is root
 *      This works because root has lesser elements on left and greater elements on right
 *        If we know, element doesnt occur on one sub-tree, we can remove it from search
 * 
 * ------ FOR NORMAL TREE
 * In this also, we search for p and q node but searching will need to be done on all nodes
 * 1. Brute Force - O(n) [T + S]
 *      Find Paths for both nodes from root
 *      Find the last common node in both paths, if matching started from root
 * 2. Recursive Postorder - O(n) [T]
 *      If at any root, both left and right LCA are set then current root is LCA
 *        return root
 *      Check p and q nodes in left and right subtree,
 *        If found in left or right, return that
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

// ! This is for normal tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
  if (root == nullptr) {
    return nullptr;
  }

  // Returning root that matches either of p and q
  // No need to search further for other node here
  // as if that other node is not found beside this subTree, it exists in this subtree
  // with this root be LCA of both
  if (root == p || root == q) {
    return root;
  }

  // If Nodes are in difference subtrees, we will search them
  TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
  TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

  // If nodes found in left and right subtree then only Root can be LCA
  if (leftLCA && rightLCA) {
    return root;
  }

  // If both nodes are in Left subtree only, then LeftLCA is LCA
  if (leftLCA) {
    return leftLCA;
  }

  // If both nodes are in Right subtree only, then RightLCA is LCA
  return rightLCA;
}

// ! This is for BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == nullptr) {
    return nullptr;
  }

  if (p->val < root->val && q->val < root->val) {
    return lowestCommonAncestor(root->left, p, q);
  } else if (p->val >= root->val && q->val >= root->val) {
    return lowestCommonAncestor(root->right, p, q);
  } else {
    return root;
  }
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
