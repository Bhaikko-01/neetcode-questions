/**
 * 1. Brute Force - O(n^2)
 *    Find nextGreater index in each iteration. This would take O(n) time
 *    ans[i] = nextGreater[i] - i
 * 2. Optimise nextGreaterIndexes using Monotonically decreasing stack - O(n) [T + S]
  *    Monotonically decreasing stack contain decreasing elements bottom to top
 *    Can be found by comparing top index of stack to current index element
 *    If element is less than current, pop till element strictly greater found
 *      Popping elements may yield stack empty that means no element found.
 *    Else that index is nextGreaterIndex for current index
 *    Push currentIndex to stack as we need to compare with recently occured index.
 *      Validity of this index will be checked by removal when checking for element strictly greater
*/

#include <bits/stdc++.h>

using namespace std;

// ! 2. This will take O(n) time as the way iteration and stack operations are handled
vector<int> getNextGreaterIndexes(vector<int>& temperatures)
{
  int n = temperatures.size();

  vector<int> nextGreaters(n, -1);

  // Mainiting indexes of element which are next greater
  stack<int> indexes;

  for (int i = n - 1; i >= 0; i--) {
    if (!indexes.empty() && temperatures[indexes.top()] > temperatures[i]) {
      nextGreaters[i] = indexes.top();
    } else {
      while (!indexes.empty() && temperatures[indexes.top()] <= temperatures[i]) {
        indexes.pop();
      }

      nextGreaters[i] = indexes.empty() ? -1 : indexes.top();
    }

    indexes.push(i);
  }

  return nextGreaters;
}

vector<int> dailyTemperatures(vector<int>& temperatures)
{
  int n = temperatures.size();

  vector<int> nextGreaterIndexes = getNextGreaterIndexes(temperatures);
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    int difference = 0;
    cout << nextGreaterIndexes[i] << " " << temperatures[i] << endl;
    if (nextGreaterIndexes[i] != -1) {
      difference = nextGreaterIndexes[i] - i;
    }
    // ans.push_back(difference);
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> temperatures(n);

  for (int i = 0; i < n; i++) {
    cin >> temperatures[i];
  }

  vector<int> ans = dailyTemperatures(temperatures);

  for (int x: ans) {
    cout << x << " ";
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
