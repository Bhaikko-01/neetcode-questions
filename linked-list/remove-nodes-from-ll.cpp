#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

ListNode* removeNodes(ListNode* head)
{
  int maxTillNow = INT_MIN;
  stack<ListNode*> pending;

  ListNode* curr = head;
  ListNode* newHead = nullptr;

  while (curr != nullptr) {
    pending.push(curr);

    curr = curr->next;
  }

  while (!pending.empty()) {
    ListNode* top = pending.top();

    if (top->val >= maxTillNow) {
      if (newHead == nullptr) {
        newHead = top;
      } else {
        top->next = newHead;
        newHead = top;
      }
    }

    maxTillNow = max(maxTillNow, top->val);

    pending.pop();
  }

  return newHead;
}

void solution()
{
  
}

int main()
{
  solution();

  return 0;
}
