#include <bits/stdc++.h>

using namespace std;

void combine(int n, int k, int currValue, vector<int>& currCombination, vector<vector<int>>& ans)
{
  if (currCombination.size() == k) {
    ans.push_back(currCombination);

    return;
  }

  if (currValue > n) {
    return;
  }


  currCombination.push_back(currValue);
  combine(n, k, currValue + 1, currCombination, ans);
  currCombination.pop_back();

  combine(n, k, currValue + 1, currCombination, ans);
}

vector<vector<int>> combine(int n, int k)
{
  vector<vector<int>> combinations;
  vector<int> currCombination;

  combine(n, k, 1, currCombination, combinations);

  return combinations;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<vector<int>> combinations = combine(n, k);

  for (auto x: combinations) {
    for (int y: x) {
      cout << y << " ";
    }
    cout << endl;
  }
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
