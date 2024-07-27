/**
 * 1. Maintain doubly LL and Hashmap
 *    For O(1) search of key, maintain hash of key and pointer to node
 *    For O(1) insert and delete, maintain doubly LL to arrange head and tail
 *      head will point to most recently used node
 *    For get,
 *      MoveTail to head while considering edge cases for head and tail
 *        by doing null checks on left and right
 *    For put,
 *      If node exists,
 *        MoveTail to head and update value if required
 *      Else
 *        Create newNode and attach to head
 *    Maintain head and tail pointers for O(1) updates in Linked List
 */

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int key;
  int value;
  Node* left;
  Node* right;

public:
  Node(int key, int value)
  {
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class LRUCache {
private:
  unordered_map<int, Node*> cache;
  Node* head;
  Node* tail;
  int currSize;
  int maxSize;

private:
  void moveNodeToFront(Node* currNode)
  {
    // ! Node is head already if its left does not exist
    if (!currNode->left) {
      return;
    }

    if (currNode->right) {
      currNode->left->right = currNode->right;
      currNode->right->left = currNode->left;
    } else {
      currNode->left->right = nullptr;
    }

    // ! If tail was currNode, update tail to left of current
    if (tail == currNode) {
      tail = tail->left;
    }

    currNode->left = nullptr;
    currNode->right = head;

    head->left = currNode;
    head = currNode;
  }

public:
  LRUCache(int capacity) {
    head = nullptr;
    tail = nullptr;
    maxSize = capacity;
    currSize = 0;
  }

  int get(int key) {
    if (!cache[key]) {
      return -1;
    }

    Node* currNode = cache[key];

    moveNodeToFront(currNode);

    return currNode->value;
  }

  void put(int key, int value)
  {
    if (!cache[key]) {
      Node* newNode = new Node(key, value);

      // ! Remove least used node at tail
      if (currSize == maxSize) {
        Node* leastUsedNode = tail;
        if (head == tail) {
          head = nullptr;
          tail = nullptr;
        } else {
          tail = tail->left;
          tail->right = nullptr;
        }

        cache[leastUsedNode->key] = nullptr;
        delete leastUsedNode;
      } else {
        currSize++;
      }

      if (head) {
        newNode->right = head;
        head->left = newNode;

        head = newNode;
      } else {
        head = newNode;
        tail = newNode;
      }

      cache[key] = newNode;

    } else {
      moveNodeToFront(cache[key]);
      cache[key]->value = value;
    }
  }
};

void solution()
{
  LRUCache lRUCache = LRUCache(2);
  lRUCache.put(1, 1); // cache is {1=1}
  lRUCache.put(2, 2); // cache is {1=1, 2=2}
  cout << lRUCache.get(1) << endl;    // return 1
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << lRUCache.get(2) << endl;    // returns -1 (not found)
  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << lRUCache.get(1) << endl;    // return -1 (not found)
  cout << lRUCache.get(3) << endl;    // return 3
  cout << lRUCache.get(4) << endl;    // return 4
}

int main()
{
  int n = 1;
  // cin >> n;

  for (int i = 1; i <= n; i++) {
    solution();
  }

  return 0;
}
