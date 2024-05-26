#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int key;
  int value;
  int counter;

  Node* left;
  Node* right;

public:
  Node(int key, int value) {
    this->key = key;
    this->value = value;
    this->counter = 1;

    this->left = nullptr;
    this->right = nullptr;
  }
};

// first = head, second = tail
typedef pair<Node*, Node*> NodePair;

class LFUCache {
private:
  unordered_map<int, Node*> mapping;
  unordered_map<int, NodePair> countListMapping;

  // Maintained to check which last counter to delete when size is full
  set<int> minCountOccurence;
  int size;
  int capacity;

private:
  void moveNodeFromPreviousCount(Node* currNode)
  {
    // Removing from previous count value
    int prevCount = currNode->counter - 1;

    NodePair pair = countListMapping[prevCount];

    if (pair.first == pair.second) {
      countListMapping.erase(prevCount);
      minCountOccurence.erase(prevCount);
    } else if (pair.first == currNode) {
      Node* rightNode = pair.first->right;

      pair.first = rightNode;
      rightNode->left = nullptr;

      countListMapping[prevCount] = pair;
    } else if (pair.second == currNode) {
      Node* leftNode = pair.second->left;

      pair.second = leftNode;
      leftNode->right = nullptr;

      countListMapping[prevCount] = pair;
    } else {
      Node* leftNode = currNode->left;
      Node* rightNode = currNode->right;

      leftNode->right = rightNode;
      rightNode->left = leftNode;

      countListMapping[prevCount] = pair;
    }

    int counterVal = currNode->counter;

    // Inserting to new count value
    if (countListMapping.find(counterVal) == countListMapping.end()) {
      NodePair newPair;

      newPair.first = currNode;
      newPair.second = currNode;

      countListMapping[counterVal] = newPair;
      minCountOccurence.insert(counterVal);
    } else {
      NodePair currPair = countListMapping[counterVal];

      Node* currHead = currPair.first;

      currNode->right = currHead;
      currHead->left = currNode;

      currPair.first = currNode;

      countListMapping[counterVal] = currPair;
    }
  }

public:
    LFUCache(int capacity) {
      this->size = 0;
      this->capacity = capacity;
    }

    int get(int key) {
      if (mapping.find(key) != mapping.end()) {
        Node* currNode = mapping[key];
        currNode->counter++;

        moveNodeFromPreviousCount(currNode);

        return currNode->value;
      }

      return -1;
    }

    void put(int key, int value)
    {
      if (mapping.find(key) == mapping.end()) {
        Node* newNode = new Node(key, value);
        int counter = newNode->counter;

        if (size >= capacity) {
          int counterToRemoveFrom = *minCountOccurence.begin();

          NodePair pair = countListMapping[counterToRemoveFrom];
          mapping.erase(pair.second->key);

          if (pair.first == pair.second) {
            countListMapping.erase(counterToRemoveFrom);
            minCountOccurence.erase(counterToRemoveFrom);
          } else {
            Node* leftNode = pair.second->left;

            pair.second->left = nullptr;
            leftNode->right = nullptr;

            pair.second = leftNode;

            countListMapping[counterToRemoveFrom] = pair;
          }
        } else {
          size++;
        }

        if (countListMapping.find(counter) == countListMapping.end()) {
          NodePair pair;
          pair.first = newNode;
          pair.second = newNode;

          countListMapping[counter] = pair;
          minCountOccurence.insert(counter);
        } else {
          NodePair pair = countListMapping[counter];

          newNode->right = pair.first;
          pair.first->left = newNode;

          pair.first = newNode;

          countListMapping[counter] = pair;
        }

        mapping[key] = newNode;
      } else {
        Node* currNode = mapping[key];

        currNode->value = value;
        currNode->counter++;

        moveNodeFromPreviousCount(currNode);
      }
    }

    void printLL()
    {
      cout << endl;
      for (auto counter: minCountOccurence) {
        cout << counter << ": ";

        NodePair currPair = countListMapping[counter];
        Node* currHead = currPair.first;

        while (currHead != nullptr) {
          cout << currHead->value << ", ";

          currHead = currHead->right;
        }
        cout << endl;
      }
      cout << endl;
    }
};

void solution()
{
  // LFUCache* lfu = new LFUCache(2);

  // lfu->put(1, 1);
  // lfu->put(2, 2);

  // cout << lfu->get(1) << endl; // 1

  // lfu->put(3, 3);
  // cout << lfu->get(2) << endl; // -1

  // cout << lfu->get(3) << endl; // 3

  // lfu->put(4, 4);
  // cout << lfu->get(1) << endl; // -1
  // cout << lfu->get(3) << endl; // 3
  // cout << lfu->get(4) << endl; // 4

  LFUCache* lfu = new LFUCache(3);

  lfu->put(2, 2);
  lfu->put(1, 1);

  cout << lfu->get(2) << endl; // 2
  cout << lfu->get(1) << endl; // 1
  cout << lfu->get(2) << endl; // 2

  lfu->put(3, 3);
  lfu->put(4, 4);

  cout << lfu->get(3) << endl; // -1
  cout << lfu->get(2) << endl; // 2
  cout << lfu->get(1) << endl; // 1
  cout << lfu->get(4) << endl; // 4
}

int main()
{
  solution();

  return 0;
}
