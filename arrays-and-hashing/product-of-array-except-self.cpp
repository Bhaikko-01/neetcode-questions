/**
 * 1. Whole array product - O(n) [T]
 *  Find product of whole array.
 *  If product is zero, then all elements are zero
 *  Else, Print multiple for each element by dividing the current ele
 * 2. Maintain Left running and Right running product - O(n) [S + T]
 *  For each element
 *    lrp[i] = lrp[i - 1] * nums[i - 1], lrp[0] = 1, 1 <= i < n
 *    rrp[i] = rrp[i + 1] * nums[i + 1], rrp[n - 1] = 1, n - 1 >= i >= 1
 *    ans[i] = lrp[i] * rrp[i]
 * 3. Using ans array for LRP and RRP - O(n) [T]
 *  For left to right iteration, store LRP at i + 1 index. Maintain prefix in variable
 *    ans[i] *= prefix; prefix *= nums[i], 0 <= i < n
 *  For right to left iteration, multiple RRP at i - 1 value which is LRP. Maintain postfix in variable
 *    ans[i] *= postfix; postfix *= nums[i], n > i >= 0
*/

#include <bits/stdc++.h>

using namespace std;

// ! 2.
vector<int> productExceptSelfLrpAndRrp(vector<int>& nums)
{
  int n = nums.size();

  vector<int> lrp(n), rrp(n);

  lrp[0] = 1;
  rrp[n - 1] = 1;

  for (int i = 1; i < n; i++) {
    lrp[i] = lrp[i - 1] * nums[i - 1];
  }

  for (int i = n - 2; i >= 0; i--) {
    rrp[i] = rrp[i + 1] * nums[i + 1];
  }

  vector<int> ans(n);

  for (int i = 0; i < n; i++) {
    ans[i] = lrp[i] * rrp[i];
  }

  return ans;
}

// ! 3.
vector<int> productExceptSelf(vector<int>& nums)
{
  int n = nums.size();
  vector<int> ans(n, 1);

  int prefixProd = 1;

  for (int i = 0; i < n; i++) {
    ans[i] *= prefixProd;
    prefixProd *= nums[i];
  }

  int post = 1;

  for (int i = n - 1; i >= 0; i--) {
    ans[i] *= post;
    post *= nums[i];
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> ans = productExceptSelf(nums);

  for (int num: ans) {
    cout << num << " ";
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

// 2 3 4 5
// 2 -> 1 * 3*4*5*6
// 3 -> 1*2 * 4*5
// 4 -> 1*2*3 * 5
// 5 -> 1*2*3*4 * 1

/**
 *      2   3   4   5
 * LPP  1   2   6   24
 * RPP  60  20  5   1
 * ans  60  40  30  24
*/

