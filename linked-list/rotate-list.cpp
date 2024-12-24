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

int listLen(ListNode* head)
{
  int len = 0;

  while (head != nullptr) {
    head = head->next;
    len++;
  }

  return len;
}

ListNode* rotateRight(ListNode* head, int k)
{
  if (head == nullptr) {
    return head;
  }

  int length = listLen(head);
  int effectiveRotation = k % length;

  if (effectiveRotation == 0) {
    return head;
  }

  ListNode* wholeReversed = reverseList(head);

  ListNode* firstPartHead = wholeReversed;
  ListNode* firstPartTail = wholeReversed;
  for (int i = 1; i < effectiveRotation; i++) {
    firstPartTail = firstPartTail->next;
  }

  ListNode* secondPartHead = firstPartTail->next;
  firstPartTail->next = nullptr;

  ListNode* firstPartHeadReverse = reverseList(firstPartHead);
  ListNode* secondPartHeadReverse = reverseList(secondPartHead);

  ListNode* firstPartHeadReverseTail = firstPartHeadReverse;
  while (firstPartHeadReverseTail->next != nullptr) {
    firstPartHeadReverseTail = firstPartHeadReverseTail->next;
  }

  firstPartHeadReverseTail->next = secondPartHeadReverse;

  return firstPartHeadReverse;
}

void solution()
{
  int k = 4;

  // ListNode* head = nullptr;

  ListNode* head = new ListNode(0);

  // head->next = new ListNode(1);
  // head->next->next = new ListNode(2);
  // head->next->next->next = new ListNode(4);
  // head->next->next->next->next = new ListNode(5);

  // ListNode* newHead = head;
  ListNode* newHead = rotateRight(head, k);

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
