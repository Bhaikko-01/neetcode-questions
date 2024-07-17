/**
 * 1. Sorting - O(nlogn)
 *      Sort array of strings using variant of lexo sort
 *      If comparing elements have different length then one with largest length is greater
 *      If same length then lexo compare should give bigger element
 */

#include <bits/stdc++.h>

using namespace std;

string kthLargestNumber(vector<string>& nums, int k)
{
  int n = nums.size();

  sort(nums.begin(), nums.end(), [](string first, string second) -> bool {
    if (first.length() == second.length()) {
      return first >= second;
    }

    return first.length() > second.length();
  });

  return nums[k - 1];
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<string> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << kthLargestNumber(nums, k) << endl;
}

int main()
{
  solution();

  return 0;
}
