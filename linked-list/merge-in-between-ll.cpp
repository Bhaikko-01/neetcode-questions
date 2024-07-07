#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
  ListNode* athPrevNode = list1;
  ListNode* bthNode = list1;

  for (int i = 0; i < a - 1; i++) {
    athPrevNode = athPrevNode->next;
  }

  for (int i = 0; i < b; i++) {
    bthNode = bthNode->next;
  }

  ListNode* athNode = athPrevNode->next;

  athPrevNode->next = list2;

  ListNode* bthNext = bthNode->next;
  bthNode->next = nullptr;

  ListNode* list2Last = list2;
  while (list2Last->next != nullptr) {
    list2Last = list2Last->next;
  }

  list2Last->next = bthNext;

  // Clearing memory
  while (athNode != nullptr) {
    ListNode* nodeToDel = athNode;

    athNode = athNode->next;
    delete nodeToDel;
  }

  return list1;
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
