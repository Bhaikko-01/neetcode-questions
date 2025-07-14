#include <bits/stdc++.h>
#include "tree-node.h"

using namespace std;

void sumNumbers(TreeNode* root, string oldNum, int& ans)
{
  if (root == nullptr) {
    return;
  }

  string currNum = oldNum + to_string(root->val);

  if (root->left == nullptr && root->right == nullptr) {
    ans += stoi(currNum);
    return;
  }

  sumNumbers(root->left, currNum, ans);
  sumNumbers(root->right, currNum, ans);
}

int sumNumbers(TreeNode* root)
{
  int ans = 0;

  sumNumbers(root, "", ans);

  return ans;
}

void solution()
{
  TreeNode* root = new TreeNode(
    1,
    new TreeNode(2),
    new TreeNode(3)
  );

  cout << sumNumbers(root) << endl;
}

int main()
{
  solution();

  return 0;
}
