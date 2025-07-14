/**
 * 1. Iterative - O(n)
 *      nodesPerPart and surplus can be determined by len/k and len%k
 *      nodesPerPart will be fixed for all parts and each part
 *        will get one from surplus
 *      This works due to pigeon hole principle and giving one to each part
 *        till surplus runs out.
 *      This way all parts size will differ by only one as remainder is equally divided
 *      Use for-loop instead of while since it is known for how long the loops has to run
 *        and use tail for each part.
 */

#include <bits/stdc++.h>
#include "list-node.h"

using namespace std;

int lenOfList(ListNode* head)
{
  int len = 0;

  while (head != nullptr) {
    len++;
    head = head->next;
  }

  return len;
}

vector<ListNode*> splitListToParts(ListNode* head, int k)
{
  int length = lenOfList(head);

  vector<ListNode*> parts(k, nullptr);

  int nodesPerPart = length / k;
  int surplus = length % k;
  int currNodeNumber = 1;

  int currPartIndex = 0;

  ListNode* curr = head;
  ListNode* currPartTail = nullptr;

  for (int i = 0; i < k; i++) {
    ListNode* currPartTail = nullptr;

    for (int j = 1; j <= nodesPerPart; j++) {
      if (currPartTail == nullptr) {
        parts[i] = curr;
        currPartTail = curr;
      } else {
        currPartTail->next = curr;
        currPartTail = currPartTail->next;
      }

      curr = curr->next;
    }

    if (surplus != 0) {
      if (currPartTail == nullptr) {
        parts[i] = curr;
        currPartTail = curr;
      } else {
        currPartTail->next = curr;
        currPartTail = currPartTail->next;
      }

      curr = curr->next;
      surplus--;
    }

    if (currPartTail) {
      currPartTail->next = nullptr;
    }
  }

  return parts;
}

void solution()
{
  ListNode* head = new ListNode(
    1, new ListNode(
      2, new ListNode(
        3, nullptr
      )
    )
  );

  int k = 5;

  vector<ListNode*> ans = splitListToParts(head, k);

  for (ListNode* currHead: ans) {
    while (currHead != nullptr) {
      cout << currHead->val << " ";

      currHead = currHead->next;
    }
    cout << endl;
  }

  cout << endl;
}

int main()
{
  solution();

  return 0;
}
