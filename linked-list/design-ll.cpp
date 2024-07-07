#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int val;
  Node* left;
  Node* right;

public:
  Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class MyLinkedList
{
private:
  Node* head;
  Node* tail;
  int len;

public:
  MyLinkedList()
  {
    head = nullptr;
    tail = nullptr;
    len = 0;
  }

  int get(int index)
  {
    if (index >= len) {
      return -1;
    }

    Node* currHead = head;
    for (int i = 1; i <= index; i++) {
      currHead = currHead->right;
    }

    return currHead->val;
  }

  void addAtHead(int val)
  {
    Node* newNode = new Node(val);

    if (head == nullptr) {
      tail = newNode;
    } else {
      head->left = newNode;
      newNode->right = head;
    }

    head = newNode;
    len++;
  }

  void addAtTail(int val)
  {
    Node* newNode = new Node(val);

    if (head == nullptr) {
      head = newNode;
    } else {
      tail->right = newNode;
      newNode->left = tail;
    }

    tail = newNode;
    len++;
  }

  void addAtIndex(int index, int val)
  {
    if (index > len) {
      return;
    }

    if (index == 0) {
      addAtHead(val);
    } else if (index == len) {
      addAtTail(val);
    } else {
      Node* newNode = new Node(val);
      Node* currNode = head;

      for (int i = 1; i <= index; i++) {
        currNode = currNode->right;
      }

      Node* leftNode = currNode->left;

      leftNode->right = newNode;
      newNode->left = leftNode;

      newNode->right = currNode;
      currNode->left = newNode;

      len++;
    }
  }

  void deleteAtIndex(int index)
  {
    if (index < 0 || index >= len) {
      return;
    }

    Node* currNode = head;

    for (int i = 1; i <= index; i++) {
      currNode = currNode->right;
    }

    Node* leftNode = currNode->left;
    Node* rightNode = currNode->right;

    if (leftNode && rightNode) {
      leftNode->right = rightNode;
      rightNode->left = leftNode;
    } else if (leftNode && !rightNode) {
      // Tail
      leftNode->right = nullptr;
      tail = leftNode;
    } else if (!leftNode && rightNode) {
      // Head
      rightNode->left = nullptr;
      head = rightNode;
    }

    delete currNode;
    len--;
  }
};

void solution()
{
  MyLinkedList myLinkedList = MyLinkedList();
  myLinkedList.addAtHead(1);
  myLinkedList.addAtTail(3);
  myLinkedList.addAtIndex(1, 2);
  cout << myLinkedList.get(1) << endl;
  myLinkedList.deleteAtIndex(1);
  cout << myLinkedList.get(1) << endl;
}

int main()
{
  solution();

  return 0;
}
