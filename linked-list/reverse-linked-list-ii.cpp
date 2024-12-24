/**
 * 1. One Pass with Reverse - O(n)
 *      Use old reverseLL algo and tweak that
 *      Maintain pointers from where to reverse list using left position
 *      Reverse list till right pointer using index and increment it
 *      Update pointers after partial reverse is done
 */

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right)
{
  ListNode* prev = nullptr;
  ListNode* next = nullptr;

  ListNode* reverseHead = head;
  ListNode* reverseHeadPrev = nullptr;

  for (int i = 1; i < left; i++) {
    reverseHeadPrev = reverseHead;
    reverseHead = reverseHead->next;
  }

  ListNode* reverseHeadStart = reverseHead;
  ListNode* reverseTail = nullptr;
  int i = left;

  while (reverseHead != nullptr) {
    if (i > right) {
      reverseTail = next;
      break;
    }

    next = reverseHead->next;
    reverseHead->next = prev;

    prev = reverseHead;
    reverseHead = next;

    i++;
  }

  ListNode* updatedList = head;

  if (reverseHeadPrev != nullptr) {
    reverseHeadPrev->next = prev;
  } else {
    updatedList = prev;
  }

  reverseHeadStart->next = reverseTail;

  return updatedList;
}

void solution()
{
  int left = 1;
  int right = 2;

  ListNode* head = new ListNode(1);

  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  // head->next->next->next = new ListNode(4);
  // head->next->next->next->next = new ListNode(5);
  // head->next->next->next->next->next = new ListNode(2);

  // ListNode* newHead = head;
  ListNode* newHead = reverseBetween(head, left, right);

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
