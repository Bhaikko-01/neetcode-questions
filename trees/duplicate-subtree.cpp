/**
 * 1. Hashmap - O(n^2)
 *      Serialize tree in any order to string
 *      Any subtree that would have same serialized string will be duplicate subtree
 *        To track this, maintain hashmap of string and vector<root>
 *      In hashmap, if for a key, value length is more than 2, then duplicate subtrees found
 */

#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

string serializeTree(TreeNode* root) {
  if (root == nullptr) {
    return "N";
  }

  return to_string(root->val) + "," + serializeTree(root->left) + "," +
         serializeTree(root->right);
}

void findDuplicateSubtrees(
  TreeNode* root,
  unordered_map<string, vector<TreeNode*>>& serializeMapping) {
  if (root == nullptr) {
    return;
  }

  string currTreeSerialized = serializeTree(root);

  serializeMapping[currTreeSerialized].push_back(root);

  findDuplicateSubtrees(root->left, serializeMapping);
  findDuplicateSubtrees(root->right, serializeMapping);
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
  vector<TreeNode*> ans;
  unordered_map<string, vector<TreeNode*>> serializeMapping;

  findDuplicateSubtrees(root, serializeMapping);

  for (unordered_map<string, vector<TreeNode*>>::iterator i = serializeMapping.begin(); i != serializeMapping.end(); i++) {
    if (i->second.size() >= 2) {
      ans.push_back(i->second[0]);
    }
  }

  return ans;
}

void solution()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(2);

  root->right = new TreeNode(3);
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(4);
  root->right->right = new TreeNode(4);

  findDuplicateSubtrees(root);
}

int main()
{
  solution();

  return 0;
}
