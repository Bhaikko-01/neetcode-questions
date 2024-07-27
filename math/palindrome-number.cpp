/**
 * 1. Reverse number
 *      Reverse only half the number till (rev < x)
 *      Palindrome if rev == x || rev / 10 == x
 *        second condition because odd num of elements cannot be broken inhalf
 *        so it would exist in rev and should be removed
 *      Numbers divisble by 10 cannot be palindrome as they have zero in end
 *        but can never have zero in front
 */

#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x)
{
  if (x < 0 || (x != 0 && x % 10 == 0)) {
    return false;
  }

  int rev = 0;

  while (rev < x) {
    rev = rev * 10 + x % 10;
    x /= 10;
  }

  return x == rev || x == rev / 10;
}

void solution()
{
  int x;
  cin >> x;

  cout << isPalindrome(x) << endl;
}

int main()
{
  solution();

  return 0;
}
