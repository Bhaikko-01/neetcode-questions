#include <bits/stdc++.h>

using namespace std;

string countAndSay(int n)
{
  if (n == 1) {
    return "1";
  }

  string converted = countAndSay(n - 1);

  int currSize = converted.size();
  char lastChar = converted[0];
  int count = 1;

  string ans = "";

  for (int i = 1; i < currSize; i++) {
    if (converted[i] == lastChar) {
      count++;
    } else {
      ans += to_string(count) + lastChar;

      lastChar = converted[i];
      count = 1;
    }
  }

  ans += to_string(count) + lastChar;

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  cout << countAndSay(n) << endl;
}

int main()
{
  solution();

  return 0;
}
