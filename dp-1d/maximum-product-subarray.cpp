/**
 * 1. Brute force - O(n^2)
 *      Generate all subarrays
 *      Find max product of all subarray and determine biggest product
 * 2. Kadane algo variation - O(n)
 *      Maintain maxProductTillNow and minProductTillNow
 *      Update both with every index. For eg
 *        possibleMax = maxTillNow * nums[i];
 *        Need to check for max(possibleMax, possibleMin) because negative number may alternate max and min
 *        maxTillNow = max(max(possibleMax, possibleMin), nums[i]);
 *      Reset maxTillNow and minTillNow if we encounter zero
 *        Do not update maxProduct as this will update 0 if that is our maxProduct
 *      Check in end of iteration if maxPossibleTillNow is more than maxSubArrayProduct
*/

#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums)
{
  int n = nums.size();

  // ! Just like kadane algo but we maintain minTillNow as well
  // ! as there can be an instance we encounter negative number and min becomes max
  int maxProduct = *max_element(nums.begin(), nums.end());
  int maxTillNow = nums[0];
  int minTillNow = nums[0];

  for (int i = 1; i < n; i++) {
    if (nums[i] == 0) {
      maxTillNow = 1;
      minTillNow = 1;
      continue;
    }

    int possibleMax = maxTillNow * nums[i];
    int possibleMin = minTillNow * nums[i];

    maxTillNow = max(max(possibleMax, possibleMin), nums[i]);
    minTillNow = min(min(possibleMax, possibleMin), nums[i]);

    maxProduct = max(maxProduct, maxTillNow);
  }

  return maxProduct;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << maxProduct(nums) << endl;
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
