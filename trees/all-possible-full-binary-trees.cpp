#include <bits/stdc++.h>
#include "tree-node.h"

using namespace std;

vector<TreeNode*> allPossibleFBT(int n)
{
  if (n == 1) {
    return { new TreeNode(0) };
  }

  vector<TreeNode*> currFBTs;

  for (int i = 1; i < n; i++) {
    int numLeftNodes = i;
    int numRightNodes = n - i - 1;

    if (!(numLeftNodes & 1) || !(numRightNodes & 1)) {
      continue;
    }

    auto leftTrees = allPossibleFBT(numLeftNodes);
    auto rightTrees = allPossibleFBT(numRightNodes);

    for (auto& l: leftTrees) {
      for (auto& r: rightTrees) {
        TreeNode* newRoot = new TreeNode(0);

        newRoot->left = l;
        newRoot->right = r;

        currFBTs.push_back(newRoot);
      }
    }
  }

  return currFBTs;
}

void solution()
{
  int n;
  cin >> n;

  allPossibleFBT(n);
}

int main()
{
  solution();

  return 0;
}
