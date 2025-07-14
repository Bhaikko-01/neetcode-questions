/**
 * 1. Recursion - O(n^2)
 *      Can use recursion stack to traverse back the list similar to reversing LL
 *      sorted head returned by recursion will contain sorted list due to how recursion works
 *      sortedHead returned by recursion call can be processed in ways
 *        compare sortedHeadItr till last with head to find head position
 *        maintain prev where head will be inserted
 *        return sortedHead after rearranging head
 *        Need to handle case if head was smallest
 * 2. Linear - O(n^2)
 *      Maintain a dummy node created new and append the small elements to
 *        create a sorted list separately rather than doing it inplace
 */

#include <bits/stdc++.h>
#include "list-node.h"

using namespace std;

ListNode* insertionSortList(ListNode* head)
{
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode* nextSortedHead = insertionSortList(head->next);

  ListNode* nextSortedHeadItr = nextSortedHead;
  ListNode* nextSortedHeadPrev = nullptr;
  ListNode* sortedHead = head;

  while (
    nextSortedHeadItr != nullptr &&
    head->val > nextSortedHeadItr->val
  ) {
    nextSortedHeadPrev = nextSortedHeadItr;
    nextSortedHeadItr = nextSortedHeadItr->next;
  }

  // * head is smallest if nextSortedHeadPrev is nullptr. It never moved forward
  if (nextSortedHeadPrev != nullptr) {
    sortedHead = nextSortedHead;
    nextSortedHeadPrev->next = head;
    head->next = nextSortedHeadItr;
  } else {
    sortedHead->next = nextSortedHead;
  }

  return sortedHead;
}

void solution()
{
  ListNode* head = new ListNode(
    1, new ListNode(
      4, new ListNode(
        3, new ListNode(
          2, nullptr
        )
      )
    )
  );

  // head = new ListNode(3, new ListNode(2, new ListNode(1)));

  ListNode* currHead = insertionSortList(head);

  while (currHead != nullptr) {
    cout << currHead->val << " ";

    currHead = currHead->next;
  }

  cout << endl;
}

int main()
{
  solution();

  return 0;
}
