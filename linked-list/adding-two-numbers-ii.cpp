#include <bits/stdc++.h>
#include "list-node.h"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
  stack<ListNode*> l1Stack, l2Stack;

  ListNode* currHead1 = l1;
  ListNode* currHead2 = l2;

  while (currHead1 != nullptr) {
    l1Stack.push(currHead1);
    currHead1 = currHead1->next;
  }

  while (currHead2 != nullptr) {
    l2Stack.push(currHead2);
    currHead2 = currHead2->next;
  }

  ListNode* headToReturn = nullptr;

  while (!l1Stack.empty() && !l2Stack.empty()) {
    currHead1 = l1Stack.top();  l1Stack.pop();
    currHead2 = l2Stack.top();  l2Stack.pop();
  }
}

void solution()
{
  ListNode* l1 = new ListNode(
    7, new ListNode(
      2, new ListNode(
        4, new ListNode(3)
      )
    )
  );

  ListNode* l2 = new ListNode(
    5, new ListNode(
      6, new ListNode(
        4
      )
    )
  );

  int carry = 0;

  addTwoNumbers(l1, l2);
}

int main()
{
  solution();

  return 0;
}
