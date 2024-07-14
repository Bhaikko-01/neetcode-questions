#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

string tree2str(TreeNode* root)
{
  if (root == nullptr) {
    return "";
  }

  string stringToReturn = to_string(root->val);

  if (!root->left && !root->right) {
    return stringToReturn;
  }

  if (root->left) {
    stringToReturn += "(";
    stringToReturn += tree2str(root->left);
    stringToReturn += ")";
  }

  if (root->right) {
    if (!root->left) {
      stringToReturn += "()";
    }

    stringToReturn += "(";
    stringToReturn += tree2str(root->right);
    stringToReturn += ")";
  }

  return stringToReturn;
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
