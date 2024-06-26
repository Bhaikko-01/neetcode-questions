#include <bits/stdc++.h>

using namespace std;

bool isVowel(char s)
{
  switch (s) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
    default:
      return false;
  }
}

int maxVowels(string s, int k)
{
  int n = s.size();

  int count = 0;
  int maxCount = 0;
  int l = 0;

  for (int i = 0; i < k; i++) {
    if (isVowel(s[i])) {
      count++;
    }
  }

  maxCount = max(maxCount, count);

  for (int i = k; i < n; i++) {
    if (isVowel(s[l++])) {
      count--;
    }

    if (isVowel(s[i])) {
      count++;
    }

    maxCount = max(maxCount, count);
  }

  return maxCount;
}

void solution()
{
  string s;
  int k;

  cin >> s >> k;

  cout << maxVowels(s, k) << endl;
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
