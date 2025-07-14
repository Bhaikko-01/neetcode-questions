/**
 * 1. Recursion - O(n^3)
 *      Intuition is to have distances to all leaf at current node
 *      Get distances of left and right subtree and compare each pair of distance
 *        if sum of them is less than allowed distance
 *      This curr node will be LCA to all nodes below so distance will be considered from this node
 *      When returning from current node to parent node,
 *        combine both array and add 1 to each value as we will go up one edge
 *      For base case
 *        - leaf would mean that parent will have one distance so return [1]
 */

#include <bits/stdc++.h>
#include "tree-node.h"

using namespace std;

vector<int> countPairs(TreeNode* root, int distance, int& ans)
{
  if (root == nullptr) {
    return vector<int>();
  }

  if (root->left == nullptr && root->right == nullptr) {
    // Returned [1] as this specifies distance as 1 from its parent node
    // to this leaf node
    return vector<int>(1, 1);
  }

  vector<int> leftSubTreeLeavesDistances = countPairs(root->left, distance, ans);
  vector<int> rightSubTreeLeavesDistances = countPairs(root->right, distance, ans);

  int n = leftSubTreeLeavesDistances.size(),
      m = rightSubTreeLeavesDistances.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (leftSubTreeLeavesDistances[i] + rightSubTreeLeavesDistances[j] <= distance) {
        ans++;
      }
    }
  }

  vector<int> combinedDistancesForParent = vector<int>(leftSubTreeLeavesDistances);
  combinedDistancesForParent.insert(
    combinedDistancesForParent.end(),
    rightSubTreeLeavesDistances.begin(),
    rightSubTreeLeavesDistances.end()
  );

  for (int i = 0; i < combinedDistancesForParent.size(); i++) {
    combinedDistancesForParent[i]++;
  }

  return combinedDistancesForParent;
}

int countPairs(TreeNode* root, int distance)
{
  int ans = 0;

  countPairs(root, distance, ans);

  return ans;
}

void solution()
{
  // TreeNode* root = new TreeNode(
  //   1,
  //   new TreeNode(
  //     2, nullptr, new TreeNode(4)
  //   ),
  //   new TreeNode(3)
  // );

  TreeNode* root = new TreeNode(
    1,
    new TreeNode(
      2,  new TreeNode(4), new TreeNode(5)
    ),
    new TreeNode(
      3, new TreeNode(6), new TreeNode(7)
    )
  );

  int distance = 3;

  int ans = countPairs(root, distance);

  cout << ans << endl;
}

int main()
{
  solution();

  return 0;
}
