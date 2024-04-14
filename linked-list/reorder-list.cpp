/**
 * 1. Use array to store LL - O(n) [T + S]
 *    This will provide random access to nodes
 *    Merge accordingly
 * 2. Length->Split->Reverse->Merge O(n) - [T] (No Extra Space)
 *    Get length of whole list
 *    Split list into two parts from len/2
 *      Element at half length should be the secondHead
 *    Reverse secondHead List
 *    Merge firstHead and secondHead list by mainting next pointers
 *      Only need to check firstHead != nullptr when merging
 *        Both list will have same length in Even length case
 *        secondHeadList will have one element extra in Odd length case
 *    If original length was ODD
 *      secondHead will have one extra element left in end
 *      Append that to tail of new list
*/

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

int length(ListNode* head)
{
  if (head == nullptr) {
    return 0;
  }

  return 1 + length(head->next);
}

ListNode* reverseListIterative(ListNode* head)
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

// ! 2.
void reorderList(ListNode* head)
{
  int len = length(head);
  ListNode* firstHead = head;
  ListNode* secondHead;

  if (len == 1) {
    return;
  }

  for (int i = 1; i <= len / 2 - 1; i++) {
    firstHead = firstHead->next;
  }

  secondHead = firstHead->next;
  firstHead->next = nullptr;

  secondHead = reverseListIterative(secondHead);

  firstHead = head;

  while (firstHead != nullptr) {
    ListNode* nextFirstHead = firstHead->next;
    ListNode* nextSecondHead = secondHead->next;

    firstHead->next = secondHead;
    secondHead->next = nextFirstHead;

    firstHead = nextFirstHead;
    secondHead = nextSecondHead;
  }

  if (len & 1) {
    firstHead = head;

    while (firstHead->next != nullptr) {
      firstHead = firstHead->next;
    }

    firstHead->next = secondHead;
  }
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
