/**
 * 1. Maintain Address Translation Map - O(n) [T + S]
 *    Copy list sequentially
 *      Create mapping of old node address to new nodes
 *    Iterate through old list again and assign random pointer using Address translation
 *      addressMapping[currHead]->random = addressMapping[currHead->random]
 * 2. Maintain cloned elements next to original
 *    Clone every element and assign to currHead->next
 *      Make sure to store currHead->next before assigning new (nextNode)
 *      clonedElement->next = nextNode
 *    Populate random pointers by iterating on currHead
 *      random pointer for clonedElement will be at currHead->random->next
 *    Remove clonedList from original list while attaching cloned list to newHead and tail
 *      Do not attach random pointer and clean cloned list together as it will affect unassigned random pointers
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomListMap(Node* head)
    {
      unordered_map<Node*, Node*> addressMapping;

      Node* currHead = head;
      Node* newHead = nullptr;
      Node* newTail = nullptr;

      while (currHead != nullptr) {
        Node* newNode = new Node(currHead->val);

        if (newHead) {
          newTail->next = newNode;
          newTail = newTail->next;
        } else {
          newHead = newNode;
          newTail = newNode;
        }

        addressMapping[currHead] = newNode;
        currHead = currHead->next;
      }

      currHead = head;

      while (currHead) {
        if (currHead->random != NULL) {
          addressMapping[currHead]->random = addressMapping[currHead->random];
        }

        currHead = currHead->next;
      }

      return newHead;
    }

    Node* copyRandomList(Node* head) {
      Node* currHead = head;

      while (currHead != nullptr) {
        Node* clonedNode = new Node(currHead->val);

        Node* nextNode = currHead->next;
        currHead->next = clonedNode;
        clonedNode->next = nextNode;

        currHead = nextNode;
      }

      currHead = head;

      while (currHead != nullptr) {
        if (currHead->random) {
          Node* oldRandom = currHead->random;

          currHead->next->random = oldRandom->next;
        }

        currHead = currHead->next->next;
      }

      Node* newHead = nullptr;
      Node* newTail = nullptr;
      currHead = head;

      while (currHead != nullptr) {
        if (newHead) {
          newTail->next = currHead->next;
          currHead->next = currHead->next->next;

          newTail = newTail->next;
        } else {
          newHead = currHead->next;
          newTail = currHead->next;

          currHead->next = newTail->next;
        }

        currHead = currHead->next;
      }

      return newHead;
    }
};

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
