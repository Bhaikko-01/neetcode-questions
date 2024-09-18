#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
  int rev = 0;
  int currNum = x;
  int maxPositiveVal = INT_MAX / 10;
  int minNegativeVal = INT_MIN / 10;

  while (currNum != 0) {
    if (rev < minNegativeVal || rev > maxPositiveVal) {
      return 0;
    }

    int rem = currNum % 10;

    rev = rev * 10 + rem;

    currNum /= 10;
  }

  return rev;
}

void solution()
{
  int x;
  cin >> x;

  cout << reverse(x) << endl;
}

int main()
{
  solution();

  return 0;
}

// 4294967295
