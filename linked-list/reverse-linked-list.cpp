/**
 * 1. Bruteforce O(n^2)
 *    Go to last of LL, pick tail and append to reversed LL
 * 2. Recursive O(n)
 *    Maintain and return tail pointer from recursion
 *      attach head to tail->next
 *      update tail to its next element before returning
 *      update head->next to null
 *    Update reveresedHead to tail once when end of LL reached in recursion in base case
 *      Make sure the variable is Passed by reference [ListNode* &reversedHead]
 * 3. Iteratively O(n)
 *    Maintain 3 pointers to store: prev = nullptr, curr = head, next
 *      Store curr->next to next
 *      Mark curr->next = prev
 *      prev = curr
 *      curr = next
*/

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

// ! 2.
ListNode* reverseList(ListNode* head, ListNode* &reversedHead)
{
  if (head == nullptr) {
    reversedHead = nullptr;
    return nullptr;
  }

  if (head->next == nullptr) {
    reversedHead = head;
    return head;
  }

  ListNode* tail = reverseList(head->next, reversedHead);
  tail->next = head;
  tail = head;
  head->next = nullptr;

  return tail;
}

// ! 2.
ListNode* reverseList(ListNode* head)
{
  ListNode* reverseHead = nullptr;

  reverseList(head, reverseHead);

  return reverseHead;
}

// ! 3.
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

// 1 -> 2 -> 3 -> 4 -> 5
