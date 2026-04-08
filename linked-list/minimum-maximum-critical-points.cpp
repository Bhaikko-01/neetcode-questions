#include <bits/stdc++.h>
#include "list-node.h"

using namespace std;

vector<int> nodesBetweenCriticalPoints(ListNode* head)
{
  ListNode* prev = nullptr;
  ListNode* currHead = head;

  int minDistance = INT_MAX,
      maxDistance = -1;
  int index = 0,
      firstIndex = -1,
      prevIndex = -1;

  while (currHead != nullptr) {
    ListNode* nextNode = currHead->next;

    if (prev != nullptr && nextNode != nullptr) {
      if (
        (prev->val > currHead->val && currHead->val < nextNode->val) ||
        (prev->val < currHead->val && currHead->val > nextNode-> val)
      ) {
        if (firstIndex == -1) {
          firstIndex = index;
          prevIndex = index;
        } else {
          minDistance = min(minDistance, index - prevIndex);

          prevIndex = index;
          maxDistance = index - firstIndex;
        }
      }
    }

    index++;
    prev = currHead;
    currHead = currHead->next;
  }

  if (minDistance == INT_MAX) {
    minDistance = -1;
  }

  return {minDistance, maxDistance};
}

void solution()
{

}

int main()
{
  solution();

  return 0;
}
