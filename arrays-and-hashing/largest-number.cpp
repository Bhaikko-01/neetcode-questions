/**
 * 1. Greedy - O(nlogn)
 *      Custom sorting logic required by picking two numbers and deciding
 *        which permutation of them will make bigger number
 *      Concat two numbers in both ways
 *        - first+second
 *        - second+first
 *      The one which gives larger number will be placed before
 *      In end sorted array, combine all numbers
 */

#include <bits/stdc++.h>

using namespace std;

string largestNumber(vector<int>& nums)
{
  sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
    string first = to_string(a) + to_string(b);
    string second = to_string(b) + to_string(a);

    return stoull(first) > stoull(second);
  });

  string num = "";
  for (int x: nums) {
    if (x == 0 && num == "") {
      continue;
    }

    num += to_string(x);
  }

  return num == "" ? "0" : num;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << largestNumber(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
