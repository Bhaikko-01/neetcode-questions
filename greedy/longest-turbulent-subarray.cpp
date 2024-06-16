#include <bits/stdc++.h>

using namespace std;

int maxTurbulenceSize(vector<int>& arr, bool initialGreater)
{
  int n = arr.size();

  bool lastGreater = initialGreater;
  int currLen = 1,
      maxLen = 1;

  for (int i = 0; i < n - 1; i++) {
    int currNum = arr[i],
        nextNum = arr[i + 1];

    if (lastGreater) {
      if (currNum < nextNum) {
        currLen++;
      } else {
        currLen = 1;
      }

      lastGreater = false;
    } else {
      if (currNum > nextNum) {
        currLen++;
      } else {
        currLen = 1;
      }

      lastGreater = true;
    }

    maxLen = max(maxLen, currLen);
  }

  return maxLen;
}

int maxTurbulenceSize(vector<int>& arr)
{
  int n = arr.size();

  return max(
    maxTurbulenceSize(arr, false),
    maxTurbulenceSize(arr, true)
  );
}

void solution()
{
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << maxTurbulenceSize(arr) << endl;
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
