#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

using pp = pair<int, int>;

int sumSubarrayMins(vector<int>& arr)
{
  stack<pp> monotonicIncreasingStack;

  // * Added so that each element is processed atleast once in while loop
  // * and we dont need to separately process stack after first pass
  arr.insert(arr.begin(), INT_MIN);
  arr.push_back(INT_MIN);

  int n = arr.size();
  int res = 0;

  for (int i = 0; i < n; i++) {
    while (
      !monotonicIncreasingStack.empty() &&
      monotonicIncreasingStack.top().second > arr[i]
    ) {
      pp currTop = monotonicIncreasingStack.top();
      int currTopIndex = currTop.first;
      int currTopNum = currTop.second;

      monotonicIncreasingStack.pop();

      int left = currTopIndex + 1;
      if (!monotonicIncreasingStack.empty()) {
        left = currTopIndex - monotonicIncreasingStack.top().first;
      }

      int right = i - currTopIndex;

      res = (res + currTopNum * left * right) % MOD;
    }

    monotonicIncreasingStack.push({ i, arr[i] });
  }

  return res;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> arr(n);

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << sumSubarrayMins(arr) << endl;
}

int main()
{
  solution();

  return 0;
}
