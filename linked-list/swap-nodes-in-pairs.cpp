/**
 * 1. Multi Pointer Approach - O(n)
 *      Maintain prev2, prev1, curr, ahead pointers
 *      Swap using them
 *        Add null checks accordingly
 */

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

ListNode* swapPairs(ListNode* head)
{
  if (!head || !head->next) {
    return head;
  }

  if (!head->next->next) {
    ListNode* newHead = head->next;
    head->next->next = head;
    head->next = nullptr;

    return newHead;
  }

  ListNode* prev1;
  ListNode* prev2;
  ListNode* curr;
  ListNode* ahead;
  ListNode* newHead;

  prev2 = nullptr;
  prev1 = head;
  curr = head->next;
  ahead = head->next->next;
  newHead = head->next;

  while (true) {
    curr->next = prev1;
    prev1->next = ahead;

    if (prev2) {
      prev2->next = curr;
    }

    swap(prev1, curr);

    if (!ahead || !ahead->next) {
      break;
    }

    ahead = ahead->next->next;
    curr = curr->next->next;
    prev1 = prev1->next->next;

    if (prev2) {
      prev2 = prev2->next->next;
    } else {
      prev2 = head;
    }
  }

  return newHead;
}

void solution()
{
  ListNode* head = new ListNode(1);

  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  // ListNode* newHead = head;
  ListNode* newHead = swapPairs(head);

  while (newHead != nullptr) {
    cout << newHead->val << " ";

    newHead = newHead->next;
  }

  cout << endl;
}

int main()
{
  solution();

  return 0;
}
