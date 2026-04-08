#include <bits/stdc++.h>
#include "list-node.h"

using namespace std;

ListNode* mergeNodes(ListNode* head)
{
  ListNode* currHead = head->next;

  int currSum = 0;

  ListNode* newListHead = nullptr;
  ListNode* newListTail = nullptr;

  while (currHead != nullptr) {
    if (currHead->val == 0) {
      ListNode* newNode = new ListNode(currSum);

      if (newListHead == nullptr) {
        newListHead = newNode;
        newListTail = newNode;
      } else {
        newListTail->next = newNode;
        newListTail = newNode;
      }

      currSum = 0;
    } else {
      currSum += currHead->val;
    }

    currHead = currHead->next;
  }

  return newListHead;
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
