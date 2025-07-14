/**
 * Simple Queue implmentation with
 *  - Insertion will update Rear and Front both
 *  - Deletion will update Rear and Front both
 */

#include <bits/stdc++.h>
#include "list-node.h"

using namespace std;

class MyCircularQueue {
private:
  int currSize;
  int maxSize;

  ListNode* front;
  ListNode* rear;
public:
  MyCircularQueue(int k) {
    this->currSize = 0;
    this->maxSize = k;

    this->front = nullptr;
    this->rear = nullptr;
  }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }

    ListNode* newNode = new ListNode(value);

    if (this->rear == nullptr) {
      this->front = newNode;
      this->rear = newNode;
    } else {
      this->rear->next = newNode;
      this->rear = newNode;
    }

    this->rear->next = this->front;

    this->currSize++;

    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }

    ListNode* currFront = this->front;

    if (this->front == this->rear) {
      this->front = nullptr;
      this->rear = nullptr;
    } else {
      // ! Make sure to update this->front too as current one will be deleted
      ListNode* currFront = this->front;

      // * This is normal Queue operation
      this->front = currFront->next;

      // * This is circular queue operation
      this->rear->next = currFront->next;
    }

    this->currSize--;

    currFront->next = nullptr;
    delete currFront;

    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }

    return this->front->val;
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }

    return this->rear->val;
  }

  bool isEmpty() {
    return this->currSize == 0;
  }

  bool isFull() {
    return this->currSize == this->maxSize;
  }
};

void solution()
{
  MyCircularQueue* obj = new MyCircularQueue(3);
  cout << obj->enQueue(1) << endl;
  cout << obj->enQueue(2) << endl;
  cout << obj->enQueue(3) << endl;
  cout << obj->enQueue(4) << endl;
  cout << obj->Rear() << endl;
  cout << obj->isFull() << endl;
  cout << obj->deQueue() << endl;
  cout << obj->enQueue(4) << endl;
  cout << obj->Rear() << endl;
}

int main()
{
  solution();

  return 0;
}
