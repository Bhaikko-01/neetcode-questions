/**
 * 1. Brute force  O(nlogn)
 *      Sort array
 * 2. Count sort - O(n) [T]
 *      Count occurence and insert elements accordingly
 *      Not a one pass algo
 * 3. One pass - O(n)
 *      Maintain pointers for position of zero and two
 *      if num == 0
 *        swap with zero pointer
 *        zero++;  // Since we found correct position for curr num
 *      if num == 1
 *        i++; // No need to take decision
 *      if num == 2
 *        swap with two pointer
 *        two--; // Since we found correct position for num
 *      Do all this while i <= two
 *      Make sure i >= zero
 *        if not then update it as zero
*/

#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums)
{
  int n = nums.size();

  int zero = 0, i = 0, two = n - 1;

  while (i <= two) {
    if (nums[i] == 0) {
      swap(nums[zero], nums[i]);
      zero++;
    } else if (nums[i] == 2) {
      swap(nums[i], nums[two]);
      two--;
    } else if (nums[i] == 1) {
      i++;
    }

    if (zero > i) {
      i = zero;
    }
  }
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  sortColors(nums);

  for (int x: nums) {
    cout << x << " ";
  }
  cout << endl;
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
