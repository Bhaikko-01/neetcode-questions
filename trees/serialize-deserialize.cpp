/**
 * 1. Recursive Preorder O(n) [S + T]
 *      Serialize in form of Preorder
 *        Values separated with commas and Null as N
 *      Deserialize by preorder
 *        Since we have Null as values stored, Tree can be derived from just Preorder
 *        Determine current value using index and data
 *          if N encountered, mark that root as null and return
 *          else Create root with value and run deserialize with successive values
*/
#include <bits/stdc++.h>
#include "./tree-node.h"

using namespace std;

// Encodes a tree to a single string.
string serialize(TreeNode* root)
{
  if (root == nullptr) {
    return "N,";
  }

  string curr = to_string(root->val) + ",";

  string leftSerialized = serialize(root->left);
  string rightSerialized = serialize(root->right);

  return curr + leftSerialized + rightSerialized;
}

TreeNode* deserialize(string data, int& index)
{
  int n = data.size();

  if (index >= n) {
    return nullptr;
  }

  string currNumber = "";
  while (index < n) {
    if (data[index] == ',') {
      break;
    }

    currNumber += data[index];
    index++;
  }

  if (currNumber == "N") {
    index++;
    return nullptr;
  }


  int currNumberConverted = stoi(currNumber);
  TreeNode* root = new TreeNode(currNumberConverted);
  index++;

  root->left = deserialize(data, index);
  root->right = deserialize(data, index);

  return root;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
  int index = 0;

  return deserialize(data, index);
}

void solution()
{
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  string serialized = serialize(root);

  cout << serialized << endl;

  TreeNode* root2 = deserialize(serialized);

  cout << root->val
    << root->left->val
    << root->right->val
    << root->right->left->val
    << root->right->right->val << endl;


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
