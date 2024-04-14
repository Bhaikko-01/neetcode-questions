/**
 *    To merge two lists, mergeTwoSortedLists will be used
 * 1. Brute Force - O(nk^3) [T]
 *      Merge two lists one by one till final list obtained
 *      Use mergeTwoSortedLists to merge
 *      Since, with each iteration, size of merged list increases,
 *        number of operations = (n + 2n + 3n + 4n + --- + kn) = nk^2
 * 2. Merge in two pairs - O(nklogk)
 *      Pick adjacent pairs and merge them
 *      Copy pointers of merged to new array of pointers
 *        If odd elements, then last pointer pushed as it is
 *      Assign mergedPointers to currentPointers
 *      Do this till currentPointers size is 1
 *      return currentPointers[0]
*/

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

class Solution {
private:
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

// ! 2.
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
      vector<ListNode*> currentLists = vector<ListNode*>(lists);
      int n = currentLists.size();

      while (n > 1) {
        vector<ListNode*> mergedLists;

        for (int i = 0; i < n && i + 1 < n; i += 2) {
          ListNode* mergedList = mergeTwoLists(currentLists[i], currentLists[i + 1]);

          mergedLists.push_back(mergedList);
        }

        if (n & 1) {
          mergedLists.push_back(currentLists[n - 1]);
        }

        currentLists = mergedLists;
        n = n / 2;
      }

      return currentLists.size() ? currentLists[0] : nullptr;
    }
};

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
