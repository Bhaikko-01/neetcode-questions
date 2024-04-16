/**
 * 1. Reverse by maintaining pointers - O(n^2)
 *      maintain pointers like currHead, prev, revHead, newHead, newTail
 *        currHead: for iteration
 *        prev: pointer before currHead
 *        revHead: Pointer to node from which should be reversed
 *        newHead, newTail: Pointer to updated LL
 *      if currCount % k == 0
 *        mark prev->next to null and reverse from revHead to prev
 *        After reverse, tail of reversed LL will be revHead
 *        Attach reversedLL head to newHead conditionally and update newTail accordingly
 *          to attach future reversedLL in O(1)
*/

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

ListNode* reverseList(ListNode* head)
{
  ListNode* prev = nullptr;
  ListNode* next = nullptr;

  while (head != nullptr) {
    next = head->next;
    head->next = prev;

    prev = head;
    head = next;
  }

  return prev;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
  ListNode* currHead = head;
  ListNode* prev = nullptr;
  ListNode* revHead = head;
  ListNode* newHead = nullptr;
  ListNode* newTail = nullptr;

  int currCount = 0;

  while (currHead != nullptr) {
    if (prev && currCount % k == 0) {
      prev->next = nullptr;

      ListNode* reverseTail = revHead;
      ListNode* reversedGroup = reverseList(revHead);

      if (!newHead) {
        newHead = reversedGroup;
      } else {
        newTail->next = reversedGroup;
      }

      newTail = reverseTail;

      revHead = currHead;
    }

    currCount++;
    prev = currHead;
    currHead = currHead->next;
  }

  if (prev && currCount % k == 0) {
    prev->next = nullptr;

    ListNode* reverseTail = revHead;
    ListNode* reversedGroup = reverseList(revHead);

    if (!newHead) {
      newHead = reversedGroup;
    } else {
      newTail->next = reversedGroup;
    }

    newTail = reverseTail;

    revHead = currHead;
  }

  newTail->next = revHead;

  return newHead;
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
