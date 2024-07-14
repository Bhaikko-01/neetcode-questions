#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
  queue<TreeNode*> pending;

  pending.push(root);

  vector<vector<int>> ans;

  if (root == nullptr) {
    return ans;
  }

  int level = 0;

  while (!pending.empty()) {
    int currLevelElements = pending.size();

    vector<int> currLevel;
    for (int i = 0; i < currLevelElements; i++) {
      TreeNode* curr = pending.front();
      pending.pop();

      currLevel.push_back(curr->val);

      if (curr->left != nullptr) {
        pending.push(curr->left);
      }

      if (curr->right != nullptr) {
        pending.push(curr->right);
      }
    }

    if (level & 1) {
      reverse(currLevel.begin(), currLevel.end());
    }

    level = level == 1 ? 0 : 1;

    ans.push_back(currLevel);
  }

  return ans;
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
