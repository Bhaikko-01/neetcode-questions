/**
 * 1. Use BFS - O(n)
 *      Traverse in BFS order
 *      When processing currNode, maintain prevNode whose next pointer is updated
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root)
{
  queue<Node*> pending;

  pending.push(root);

  while (!pending.empty()) {
    int currElCount = pending.size();

    Node* prev = nullptr;

    for (int i = 1; i <= currElCount; i++) {
      Node* curr = pending.front();
      pending.pop();

      if (prev) {
        prev->next = curr;
      }
      prev = curr;

      if (curr) {
        pending.push(curr->left);
        pending.push(curr->right);
      }
    }
  }

  return root;
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
