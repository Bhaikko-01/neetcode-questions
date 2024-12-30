/**
 * 1. BFS with ID assign like in Heap - O(n)
 *      Run BFS of tree with assigning an ID to left and right child of each node
 *      Assign ID in advance when pushing child to queue
 *      ! To Prevent signed overflow, relative IDs are assigned based on curr level
 *        ! Before assigning, (currNodeId - leftMostNumId) is done so
 *        ! leftChildId = 2 * (currNodeId - leftMostNumId)
 *        ! rightChildId = 2 * (currNodeId - leftMostNumId) + 1
 *        According to this, leftMost node will always start with 0 ID at that level
 *      At end of traversing each level, maxWidth = max(maxWidth, rightId - leftId + 1)
 */

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

typedef long long ll;

int widthOfBinaryTree(TreeNode* root)
{
  queue<TreeNode*> pending;
  unordered_map<TreeNode*, ll> nodeIdMapping;

  pending.push(root);
  nodeIdMapping[root] = 1;

  int maxWidth = 0;

  while (!pending.empty()) {
    int currLevelNodes = pending.size();

    ll leftId = -1,
       rightId = -1;

    // ! This is just stupid. Hack to prevent signed overflow
    ll leftMostNum = -1;

    for (int nodeCount = 1; nodeCount <= currLevelNodes; nodeCount++) {
      TreeNode* currNode = pending.front();
      pending.pop();

      ll currNodeId = nodeIdMapping[currNode];
      if (leftMostNum == -1) {
        leftMostNum = currNodeId;
      }

      if (currNode->left) {
        pending.push(currNode->left);

        // !  Possible if not to prevent signed overflow
        // nodeIdMapping[currNode->left] = 2 * (currNodeId);

        // ! Need to do to prevent signed overflow
        nodeIdMapping[currNode->left] = 2 * (currNodeId - leftMostNum);
      }

      if (currNode->right) {
        pending.push(currNode->right);
        // !  Possible if not to prevent signed overflow
        // nodeIdMapping[currNode->right] = 2 * (currNodeId) + 1;

        // ! Need to do to prevent signed overflow
        nodeIdMapping[currNode->right] = 2 * (currNodeId - leftMostNum) + 1;
      }

      if (leftId == -1) {
        leftId = currNodeId;
      }
      rightId = currNodeId;
    }

    if (leftId != -1 && rightId != -1) {
      maxWidth = max(maxWidth, (int)(rightId - leftId + 1));
    }
  }

  return maxWidth;
}

void solution()
{
  // TreeNode* root = new TreeNode(
  //   1,
  //   new TreeNode(
  //     3,
  //     new TreeNode(5),
  //     new TreeNode(3)
  //   ),
  //   new TreeNode(
  //     2,
  //     nullptr,
  //     new TreeNode(9)
  //   )
  // );

  TreeNode* root = new TreeNode(
    1,
    new TreeNode(
      3,
      new TreeNode(
        5,
        new TreeNode(6),
        nullptr
      ),
      nullptr
    ),
    new TreeNode(
      2,
      nullptr,
      new TreeNode(
        9,
        new TreeNode(7),
        nullptr
      )
    )
  );

  cout << widthOfBinaryTree(root) << endl;
}

int main()
{
  solution();

  return 0;
}
