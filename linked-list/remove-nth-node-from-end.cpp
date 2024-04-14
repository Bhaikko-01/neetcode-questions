/**
 * 1. Brute Force - O(n)
 *    Get length and delete (len - n + 1) node from beginning
 * 2. Two pointer - O(n)
 *    Maintain three pointers,
 *      prev, left, right
 *    Move right by n times to get n offset between left and right
 *    Move left and right till right is nullptr.
 *      right nullptr means right is at end and left will be at n offset from right which is n from last
 *    Keep prev just before left,
 *      before updating left to its next, make prev = left
 *    Few cases can exist
 *      If left is head (n == length)
 *        return head->next
 *      Else If left->next is nullptr (n == 1)
 *        Mark prev->next = nullptr, no need to assign to next pointer
 *      Else prev->next = left->next
*/

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n)
{
  ListNode* left = head;
  ListNode* right = head;
  ListNode* prev = nullptr;

  for (int i = 1; i <= n; i++) {
    right = right->next;
  }

  while (right != nullptr) {
    prev = left;
    left = left->next;
    right = right->next;
  }

  if (left == head) {
    head = head->next;
  } else {
    if (left->next) {
      prev->next = left->next;
      delete left;
    } else {
      delete prev->next;
      prev->next = nullptr;
    }
  }

  return head;
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
