/**
 * 1. Two pointer with Sorted O(nlogn)
 *      Sort the array
 *      Consider each element as min of a subsequence and find possible max for that subsequence
 *      Move r to left till nums[r] > remainSum
 *        count += 2^(r - l)
 */

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int modpower2(int n)
{
  if (n == 0) {
    return 1 % MOD;
  }

  ll u = modpower2(n / 2);
  u = (u * u) % MOD;

  if (n & 1) {
    u = (u * 2) % MOD;
  }

  return u;
}

int numSubseq(vector<int>& nums, int target)
{
  int n = nums.size();

  sort(nums.begin(), nums.end());

  int l = 0, r = n - 1;
  ll count = 0;

  for (l; l < n; l++) {
    int remainSum = target - nums[l];

    while (r >= l && nums[r] > remainSum) {
      r--;
    }

    if (l <= r) {
      count = count % MOD + modpower2(r - l);
    }
  }

  return count;
}

void solution()
{
  int n, target;
  cin >> n >> target;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << numSubseq(nums, target) << endl;
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
