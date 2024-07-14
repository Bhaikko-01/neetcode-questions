#include <bits/stdc++.h>
#include "tree-node.h"

using namespace std;

bool isCompleteTree(TreeNode* root) {
  queue<TreeNode*> pending;

  pending.push(root);

  bool nullFound = false;

  while (!pending.empty()) {
    int currLevelCount = pending.size();

    for (int i = 0; i < currLevelCount; i++) {
      TreeNode* top = pending.front();
      pending.pop();

      if (nullFound) {
        if (top != nullptr) {
          return false;
        }
      } else {
        if (top) {
          pending.push(top->left);
          pending.push(top->right);
        } else {
          nullFound = true;
        }
      }
    }
  }

  return true;
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
