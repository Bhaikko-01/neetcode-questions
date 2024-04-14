/**
 * 1. Hare and tortoise double pointer - O(n)
 *    All elements are in range [1, n] that means they can be treated as index
 *    Use hare and tortoise algo to find intersection
 *      Cycle will exist if two values in array point to same value by index
 *        meaning they have more than 2 out-degree
 *    After intersection is found,
 *      Use entry pointer and slow pointer to detect start of cycle
 *        Match them till they are equal
 *      Slow pointer will be answer as two indexes will be pointing to this number which is treated as index
 *        return slow;
*/
#include <bits/stdc++.h>

using namespace std;

// ! 1.
int findDuplicate(vector<int>& nums)
{
  int firstIndex = nums[0];
  int slow = nums[firstIndex];
  int fast = nums[slow];

  while (fast != slow) {
    fast = nums[nums[fast]];
    slow = nums[slow];
  }

  int entry = nums[0];

  while (entry != slow) {
    cout << entry << " " << slow << endl;
    entry = nums[entry];
    slow = nums[slow];
  }

  return slow;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << findDuplicate(nums) << endl;
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
