/**
 * 1. Queue - O(n)
 *      Push root and nullptr to queue
 *      nullptr will be treated as next level indicator
 *        Process root and push left and right if they exist
 *      if queue has only one element and is nullptr -> No more traversal possible
 *      else continue processing queue top
 * Note: Instead of nullptr, at each iteration,
 *  can process number of elements in queue at that iteration using for-loop
 *    this would mean processing, we are processing all nodes at one specific level
 *    Ater loop finishes, we go to next level
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

// ! 1
vector<vector<int>> levelOrder(TreeNode* root)
{
  vector<vector<int>> levelOrderTraversal;
  vector<int> currLevel;

  if (!root) {
    return levelOrderTraversal;
  }

  queue<TreeNode*> pending;
  pending.push(root);
  pending.push(nullptr);

  while (true) {
    if (pending.size() == 1 && pending.front() == nullptr) {
      levelOrderTraversal.push_back(currLevel);
      break;
    }

    TreeNode* curr = pending.front();
    pending.pop();

    if (curr) {
      currLevel.push_back(curr->val);

      if (curr->left) {
        pending.push(curr->left);
      }

      if (curr->right) {
        pending.push(curr->right);
      }
    } else {
      levelOrderTraversal.push_back(currLevel);
      currLevel = vector<int>();

      pending.push(nullptr);
    }
  }

  return levelOrderTraversal;
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
