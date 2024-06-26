/**
 * 1. Brute Force - O(n^2)
 *      For each cycle, maintained using offset variable ranging from [0, n-1]
 *      Count occurence of zero and one at even and odd index respectively
 *      For current cycle, currAnswer would be
 *        can be (n - oneAtEven - zeroAtOdd) OR (n - oneAtOdd - zeroAtEven)
 *          as the answer will be number of changes required
 *          Both possibilities because we need to create alternating string starting with either 0 or 1
 *      ans = min(ans, currAns)
 *
 * 2. Sliding Window - O(n)
 *      Calculating oneAtEven, zeroAtOdd, oneAtOdd, zeroAtEven are repititive as we are incrementing offset
 *      Since values just shift by one index, we simply swap oneAtEven, oneAtOdd and zeroAtEven, zeroAtOdd
 *        If Size is odd meaning extreme index are even, then oneAtEven and zeroAtEven will behave slightly different
 *          After swapping, increment zeroAtEven and decrement zeroAtOdd since extreme will still be at even index
 *           or oneAtEven and oneAtOdd based on s[offset]
 *      For current cycle, currAnswer would be
 *        can be (n - oneAtEven - zeroAtOdd) OR (n - oneAtOdd - zeroAtEven)
 *          as the answer will be number of changes required
 *          Both possibilities because we need to create alternating string starting with either 0 or 1
 *      ans = min(ans, currAns)
 */

#include <bits/stdc++.h>

using namespace std;

int minFlips(string s)
{
  int n = s.size();
  int minFlipCount = INT_MAX;

  int oneAtEven = 0,
    zeroAtOdd = 0,
    oneAtOdd = 0,
    zeroAtEven = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (i & 1) {
        zeroAtOdd++;
      } else {
        zeroAtEven++;
      }
    } else {
      if (i & 1) {
        oneAtOdd++;
      } else {
        oneAtEven++;
      }
    }
  }

  for (int offset = 0; offset < n; offset++) {
    int case1 = n - oneAtEven - zeroAtOdd;
    int case2 = n - oneAtOdd - zeroAtEven;

    minFlipCount = min(minFlipCount, min(case1, case2));

    swap(oneAtEven, oneAtOdd);
    swap(zeroAtOdd, zeroAtEven);

    if (n & 1) {
      if (s[offset] == '0') {
        zeroAtEven++;
        zeroAtOdd--;
      } else {
        oneAtEven++;
        oneAtOdd--;
      }
    }
  }

  return minFlipCount;
}

int minFlipsBrute(string s)
{
  int n = s.size();
  int minFlipCount = INT_MAX;

  for (int offset = 0; offset < n; offset++) {
    int oneAtEven = 0,
        zeroAtOdd = 0,
        oneAtOdd = 0,
        zeroAtEven = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (((i + offset) % n) & 1) {
          zeroAtOdd++;
        } else {
          zeroAtEven++;
        }
      } else {
        if (((i + offset) % n) & 1) {
          oneAtOdd++;
        } else {
          oneAtEven++;
        }
      }
    }

    int case1 = n - oneAtEven - zeroAtOdd;
    int case2 = n - oneAtOdd - zeroAtEven;

    minFlipCount = min(minFlipCount, min(case1, case2));
  }

  return minFlipCount;
}

void solution()
{
  string s;
  cin >> s;

  cout << minFlips(s) << endl;
  // cout << minFlipsBrute(s) << endl;
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
