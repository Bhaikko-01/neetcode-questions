/**
 * 1. Hashmap - O(n) [T + S]
 *    Keep track of addresses traversed
 *    IF already occuring address found, cycle exist
 *    If nullptr found, no cycle
 * 2. Two pointer (Hare and Tortoise method) O(n)
 *    maintain fast and slow pointer
 *      fast = fast->next->next;
 *      slow = slow->next;
 *    If at any given point, they are equal => cycle exists
 *    Else if null found, cycle does not exist
 *    This works as fast pointer will eventually catch up to slow pointer
 *      Distance between these pointers will reduce by 1 in each iteration
 *      Initially, we have 1 distance and need to cover n - 1 distance
 *        At each iteration, it will reduce by 1 hence O(n)
 *
 * --------------- Linked List cycle 2
 * 1. Match Entry pointer with intersection slow pointer
 *    After finding intersection point using above algo, (Hare and Tortoise method)
 *      Move entryPointer and slow together till they are equal
 *      That node is cycle starter
 *    This works because fast travels twice the distance slow travels
 *      2*slow = fast
 *      2(l1 + l2) = l1 + l2 + l3
 *        l1 = l3 -> Move l1 same as l3 to reach cycle start
 *        l1 is distance till cycle start which is travelled by both
 *        l2 is distance travelled from cycle start till intersection met. Not node distance but total distance
 *        l3 is distance travelled from intersection point till start of cycle
*/

#include <bits/stdc++.h>
#include "./list-node.h"

using namespace std;

class Solution {
public:
    // ! 2.
    bool hasCycle(ListNode *head)
    {
      if (!head || !head->next) {
        return false;
      }

      ListNode* fast = head->next->next;
      ListNode* slow = head->next;

      while (fast != nullptr && fast->next != nullptr) {
        if (fast == slow) {
          return true;
        }

        fast = fast->next->next;
        slow = slow->next;
      }

      return false;
    }

    // ! Linked List cycle 2
    ListNode *detectCycle(ListNode *head) {
      if (!head || !head->next) {
        return nullptr;
      }

      ListNode* fast = head->next->next;
      ListNode* slow = head->next;

      while (fast != nullptr && fast->next != nullptr) {
        if (fast == slow) {
          ListNode* entry = head;

          while (entry != slow) {
            entry = entry->next;
            slow = slow->next;
          }

          return slow;
        }

        fast = fast->next->next;
        slow = slow->next;
      }

      return nullptr;
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
