#include <bits/stdc++.h>

using namespace std;

inline string getKey(int x, int y) {
  return to_string(x) + "," + to_string(y);
}

int minSteps(int currChars, int copyBuffer, int n, unordered_map<string, int>& occured)
{
  if (currChars == n) {
    return 0;
  }

  if (currChars > n) {
    return INT_MAX;
  }

  if (copyBuffer > n) {
    return INT_MAX;
  }

  string key = getKey(currChars, copyBuffer);

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  int charCopied = INT_MAX;
  if (currChars != copyBuffer) {
    charCopied = minSteps(currChars, currChars, n, occured);
  }

  int charPasted = minSteps(currChars + copyBuffer, copyBuffer, n, occured);

  int minOfTwo = min(charCopied, charPasted);

  occured[key] = minOfTwo;

  if (minOfTwo == INT_MAX) {
    return minOfTwo;
  }

  occured[key] = minOfTwo + 1;

  return occured[key];
}

int minSteps(int n)
{
  if (n == 1) {
    return 0;
  }

  unordered_map<string, int> occured;

  return minSteps(1, 1, n, occured) + 1;
}

void solution()
{
  int n;
  cin >> n;

  cout << minSteps(n) << endl;
}

int main()
{
  solution();

  return 0;
}
