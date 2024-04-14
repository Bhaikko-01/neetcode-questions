/**
 * 1. Iterative merge - O(m + n)
 *    Maintain new mergedHead and mergedTail
 *    Compare current heads and merge to new head whose value is less
 *    After both iteration, run indiviual iterations to merge rest of list
 *      mergedHead can be null in these cases as well
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
