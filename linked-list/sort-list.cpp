/**
 * 1. Merge Sort - O(nlogn)
 *      Find mid of list and separate list into two halves
 *      Call mergeSort on both lists
 *        Base case would be if head is null or head->next is null
 *      Call mergeTwoSortedList and return the mergedHead
 */

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
  ListNode* mergedHead = nullptr;
  ListNode* mergedTail = nullptr;

  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val < list2->val) {
      if (mergedHead == nullptr) {
        mergedHead = list1;
        mergedTail = list1;
      } else {
        mergedTail->next = list1;
        mergedTail = mergedTail->next;
      }

      list1 = list1->next;
    } else {
      if (mergedHead == nullptr) {
        mergedHead = list2;
        mergedTail = list2;
      } else {
        mergedTail->next = list2;
        mergedTail = mergedTail->next;
      }

      list2 = list2->next;
    }
  }

  while (list1 != nullptr) {
    if (mergedTail) {
      mergedTail->next = list1;
      mergedTail = mergedTail->next;
    } else {
      mergedHead = list1;
      mergedTail = list1;
    }

    list1 = list1->next;
  }

  while (list2 != nullptr) {
    if (mergedTail) {
      mergedTail->next = list2;
      mergedTail = mergedTail->next;
    } else {
      mergedHead = list2;
      mergedTail = list2;
    }

    list2 = list2->next;
  }

  return mergedHead;
}

ListNode* getMid(ListNode* head)
{
  ListNode* slow = head;
  ListNode* fast = head;

  while (
    fast != nullptr &&
    fast->next != nullptr &&
    fast->next->next != nullptr
  ) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

ListNode* sortList(ListNode* head)
{
  if (head == nullptr) {
    return nullptr;
  }

  if (head->next == nullptr) {
    return head;
  }

  ListNode* midNode = getMid(head);
  ListNode* nextMidNode = midNode->next;
  midNode->next = nullptr;

  ListNode* leftSorted = sortList(head);
  ListNode* rightSorted = sortList(nextMidNode);

  return mergeTwoLists(leftSorted, rightSorted);
}

void solution()
{
  ListNode* head = new ListNode(-1);

  head->next = new ListNode(5);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(0);

  // ListNode* newHead = head;
  ListNode* newHead = sortList(head);

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
