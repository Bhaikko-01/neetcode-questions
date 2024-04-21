/**
 * 1. Recursive Clone - O(n*m)
 *      Clone current node and clone neighbors recursively
 *        Subproblem would be cloning neighbors
 *        Base case is if node is already cloned so we keep mapping
 *        Attach to graph obtained from subproblem to neighbor of current cloned node
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;

  Node() {
      val = 0;
      neighbors = vector<Node*>();
  }
  Node(int _val) {
      val = _val;
      neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
      val = _val;
      neighbors = _neighbors;
  }
};

Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& clonedNodeMapping)
{
  if (!node) {
    return nullptr;
  }

  if (clonedNodeMapping[node]) {
    return clonedNodeMapping[node];
  }

  Node* clonedNode = new Node(node->val);
  clonedNodeMapping[node] = clonedNode;

  for (Node* neighbor: node->neighbors) {
    Node* clonedNeighbor = cloneGraph(neighbor, clonedNodeMapping);
    clonedNode->neighbors.push_back(clonedNeighbor);
  }

  return clonedNode;
}

Node* cloneGraph(Node* node)
{
  unordered_map<Node*, Node*> clonedNodeMapping;

  return cloneGraph(node, clonedNodeMapping);
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
