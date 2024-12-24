/**
 * 1. Create two lists and Join them - O(n)
 *      Create two separate lists, lessThan and moreThan
 *        go through list and append on two lists based on curr->val
 *      After separation, join lessThanTail->next = moreThanHead
 */

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

ListNode* partition(ListNode* head, int x)
{
  ListNode* lessThanHead = nullptr;
  ListNode* lessThanTail = nullptr;
  ListNode* moreThanHead = nullptr;
  ListNode* moreThanTail = nullptr;

  ListNode* currHead = head;

  while (currHead != nullptr) {
    ListNode* nextHead = currHead->next;

    if (currHead->val < x) {
      if (lessThanHead == nullptr) {
        lessThanHead = currHead;
        lessThanTail = currHead;
      } else {
        lessThanTail->next = currHead;
        lessThanTail = lessThanTail->next;
      }
    } else {
      if (moreThanHead == nullptr) {
        moreThanHead = currHead;
        moreThanTail = currHead;
      } else {
        moreThanTail->next = currHead;
        moreThanTail = moreThanTail->next;
      }
    }

    currHead->next = nullptr;
    currHead = nextHead;
  }

  if (lessThanHead == nullptr) {
    return moreThanHead;
  }

  lessThanTail->next = moreThanHead;
  return lessThanHead;
}

void solution()
{
  int x = 2;
  ListNode* head = new ListNode(2);

  head->next = new ListNode(1);
  // head->next->next = new ListNode(3);
  // head->next->next->next = new ListNode(2);
  // head->next->next->next->next = new ListNode(5);
  // head->next->next->next->next->next = new ListNode(2);

  // ListNode* newHead = head;
  ListNode* newHead = partition(head, x);

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
