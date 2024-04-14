/**
 * 1. Add with tracking carry from last add
 *    Add head1 and head2 and create newNode based on it
 *    Append newNode using head and tail for new LL
 *    Check if newNode gives a carry
 *      carry = newNode->val >= 10 ? 1 : 0;
 *      newNode->val = newNode->val % 10;
 *    Append remaining nodes by adding carry and checking if carry exist
 *    In end, check if carry exist
 *      If exists, append newNode(1)
 *      Else do nothing
*/

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
      ListNode* head1 = l1;
      ListNode* head2 = l2;

      ListNode* head = nullptr;
      ListNode* tail = nullptr;

      int carry = 0;

      while (head1 != nullptr && head2 != nullptr) {
        ListNode* addedHead = new ListNode(head1->val + head2->val + carry);

        carry = addedHead->val >= 10 ? 1 : 0;
        addedHead->val = addedHead->val % 10;

        if (head) {
          tail->next = addedHead;
          tail = tail->next;
        } else {
          head = addedHead;
          tail = addedHead;
        }

        head1 = head1->next;
        head2 = head2->next;
      }

      while (head1 != nullptr) {
        ListNode* copiedHead = new ListNode(head1->val + carry);
        tail->next = copiedHead;
        tail = tail->next;

        carry = tail->val >= 10 ? 1 : 0;
        tail->val = tail->val % 10;

        head1 = head1->next;
      }

      while (head2 != nullptr) {
        ListNode* copiedHead = new ListNode(head2->val + carry);
        tail->next = copiedHead;
        tail = tail->next;

        carry = tail->val >= 10 ? 1 : 0;
        tail->val = tail->val % 10;

        head2 = head2->next;
      }

      if (carry) {
        tail->val = tail->val % 10;

        ListNode* copiedHead = new ListNode(carry);
        tail->next = copiedHead;
        tail = tail->next;
      }

      return head;
    }
};

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
