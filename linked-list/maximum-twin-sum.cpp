/**
 * 1. Slow and Fast pointer
 *      Find mid of LL using slow and fast
 *      Use recursion to reach end of LL from slow->next
 *        using forward and backward pointer
 *        find maxSum accordingly
 *        update forward pointer
*/

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

void pairSum(ListNode* &forward, ListNode* &backward, int& maxSum)
{
  if (backward == nullptr) {
    return;
  }

  pairSum(forward, backward->next, maxSum);

  maxSum = max(maxSum, forward->val + backward->val);

  forward = forward->next;
}

int pairSum(ListNode* head)
{
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  int maxSum = 0;

  pairSum(head, slow->next, maxSum);

  return maxSum;
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
