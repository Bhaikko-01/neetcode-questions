#include <bits/stdc++.h>
#include "list-node.h"

using namespace std;

ListNode* modifiedList(vector<int>& nums, ListNode* head)
{
  int n = nums.size();

  unordered_set<int> numbers;
  for (int num: nums) {
    numbers.insert(num);
  }

  ListNode* currHead = head;
  ListNode* prev = nullptr;

  while (currHead != nullptr) {
    int val = currHead->val;

    ListNode* nodeToDelete = nullptr;

    if (numbers.find(val) != numbers.end()) {
      nodeToDelete = currHead;

      if (prev == nullptr) {
        head = head->next;
      } else {
        prev->next = currHead->next;
      }
    } else {
      prev = currHead;
    }

    currHead = currHead->next;

    // ! Comment this out when running code on Leetcode
    delete nodeToDelete;
  }

  return head;
}

void solution()
{
  vector<int> nums = {1};
  ListNode* head = new ListNode(
    1, new ListNode(
      2, new ListNode(
        1, new ListNode(
          2, new ListNode(
            1, new ListNode(
              2
            )
          )
        )
      )
    )
  );

  ListNode* newHead = modifiedList(nums, head);

  while (newHead != nullptr) {
    cout << newHead->val << endl;

    newHead = newHead->next;
  }


}

int main()
{
  solution();

  return 0;
}
