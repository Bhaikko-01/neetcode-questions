/**
 * 1. Recursive Post Order O(n)
 *      Similar to finding diameter where whole tree context is required for determining answer
 *      Traverse tree in post order
 *      At each root, there are 4 possible paths that can be considered for maxValue
 *        leftPath + rightPath + root
 *        root
 *        leftPath + root
 *        rightPath + root
 *      maxVal should be max of these
 *      For subtree return,
 *        We would return max possible maxPath down till root
 *        leftPath + rightPath + root cannot be valid path in subtree as it goes back down
 *        root, leftPath + root, rightPath + root are valid path,
 *          max of these are returned for a Subtree
*/

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

int maxPathSum(TreeNode* root, int& maxSum)
{
  if (root == nullptr) {
    return 0;
  }

  int leftPathSum = maxPathSum(root->left, maxSum);
  int rightPathSum = maxPathSum(root->right, maxSum);
  int val1 = leftPathSum + rightPathSum + root->val;
  int val2 = root->val;
  int val3 = leftPathSum + root->val;
  int val4 = rightPathSum + root->val;

  vector<int> currVals = { maxSum, val1, val2, val3, val4 };
  maxSum = *max_element(currVals.begin(), currVals.end());

  return max(val2, max(val3, val4));
}

int maxPathSum(TreeNode* root)
{
  int ans = INT_MIN;

  maxPathSum(root, ans);

  return ans;
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
