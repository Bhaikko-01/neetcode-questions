/**
 * 1. Recursive O(n^2)
 *      Inorder is Left Root Right
 *      Pre order is Root Left Right
 *      First element of Preorder will be root of a tree
 *        Find this element in InOrder,
 *          all elements to left of this will belong to leftSubtree of root
 *          all elements to right of this will belong to rightSubtree of root
 *        Number of elements to left in inorder will belong to leftSubtree from preorder
 *        Number of elements to right in inorder will belong to rightSubtree from preorder
 *      buildTree by passing pointers based on length derived from indexInInorder
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

TreeNode* buildTree(vector<int>& preorder, int lp, int rp, vector<int>& inorder, int li, int ri)
{
  if (lp > rp) {
    return nullptr;
  }

  if (lp == rp) {
    TreeNode* root = new TreeNode(preorder[lp]);
    return root;
  }

  int currRoot = preorder[lp];
  int rootPosInInorder = -1;
  for (int i = li; i <= ri; i++) {
    if (inorder[i] == currRoot) {
      rootPosInInorder = i;
      break;
    }
  }

  int elementsInLeftSubTree = rootPosInInorder - li;

  TreeNode* root = new TreeNode(preorder[lp]);

  TreeNode* leftSubTree = buildTree(preorder, lp + 1, lp + elementsInLeftSubTree, inorder, li, rootPosInInorder - 1);
  TreeNode* rightSubTree = buildTree(preorder, lp + elementsInLeftSubTree + 1, rp, inorder, rootPosInInorder + 1, ri);

  root->left = leftSubTree;
  root->right = rightSubTree;

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
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
