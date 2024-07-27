/**
 * 1. Backtracking
 *      Maintain concatenated string to check with currEl of arr
 *      Check if using currString has duplicate with concatenated
 *        If duplicate found, check withoutInclude only
 *        Else max(withInclude + length, withoutInclude)
 */

#include <bits/stdc++.h>

using namespace std;

bool isDuplicate(string& first, string& second)
{
  unordered_map<int, bool> occured;

  for (char x: first) {
    if (occured[x]) {
      return true;
    }

    occured[x] = true;
  }

  for (char x: second) {
    if (occured[x]) {
      return true;
    }

    occured[x] = true;
  }

  return false;
}

int maxLength(vector<string>& arr, int currIndex, string picked)
{
  int n = arr.size();

  if (currIndex == n) {
    return 0;
  }

  string currString = arr[currIndex];

  bool duplicateFound = isDuplicate(picked, currString);

  int withoutInclude = maxLength(arr, currIndex + 1, picked);
  int withInclude = 0;

  if (!duplicateFound) {
    withInclude = maxLength(arr, currIndex + 1, picked + currString) + currString.length();
  }

  return max(withInclude, withoutInclude);
}

int maxLength(vector<string>& arr)
{
  unordered_map<int, bool> mapping;

  vector<string> validStrings;

  return maxLength(arr, 0, "");
}

void solution()
{
  int n;
  cin >> n;

  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << maxLength(arr) << endl;
}

int main()
{
  solution();

  return 0;
}
