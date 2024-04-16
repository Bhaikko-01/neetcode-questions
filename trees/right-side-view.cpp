/**
 * 1. DFS - O(n) [T + S]
 *      Maintain map that would track if at a depth, we have seen right
 *      If not seen
 *        push root to ans and mark that depth seen
 *      Traverse tree in reverse pre-order where right is processed before left
 * 2. BFS - O(n) [T + S]
 *      Do normal level order traversal using queue
 *      Instead of pushing left first, we push right first to queue
 *      The first element in that level will be right most,
 *        this can be determined by using for-loop techinique at each iteration
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

// ! 1.
void rightSideView(TreeNode* root, unordered_map<int, bool>& occured, int depth, vector<int>& rightView)
{
  if (root == nullptr) {
    return;
  }

  if (!occured[depth]) {
    rightView.push_back(root->val);
    occured[depth] = true;
  }

  rightSideView(root->right, occured, depth + 1, rightView);
  rightSideView(root->left, occured, depth + 1, rightView);
}

vector<int> rightSideView(TreeNode* root)
{
  vector<int> rightView;
  unordered_map<int, bool> occured;

  rightSideView(root, occured, 0, rightView);

  return rightView;
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
