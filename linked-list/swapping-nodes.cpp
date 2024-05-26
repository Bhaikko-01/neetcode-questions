#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

// ! Similar to remove kth node from end
ListNode* swapNodes(ListNode* head, int k)
{
  ListNode* begin = head;
  ListNode* end = head;

  for (int i = 1; i <= k - 1; i++) {
    begin = begin->next;
  }

  ListNode* currHead = begin->next;
  while (currHead != nullptr) {
    currHead = currHead->next;
    end = end->next;
  }

  swap(begin->val, end->val);

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
