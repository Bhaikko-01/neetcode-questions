#include <bits/stdc++.h>

using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k)
{
  int n = colors.size();

  stack<int> alternating;

  for (int i = 0; i < k - 1; i++) {
    if (!alternating.empty() && alternating.top() == colors[i]) {
      alternating = {};
    }

    alternating.push(colors[i]);
  }

  int ans = 0;

  int l = 0, r = k - 1;
  int endIndex = r;

  bool firstPassDone = false;

  while (!firstPassDone || r != endIndex) {
    firstPassDone = true;

    if (!alternating.empty() && alternating.top() == colors[r]) {
      alternating = {};
    }

    alternating.push(colors[r]);

    if (alternating.size() >= k) {
      ans++;
    }

    l = (l + 1) % n;
    r = (r + 1) % n;
  }

  return ans;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> colors(n);
  for (int i = 0; i < colors.size(); i++) {
    cin >> colors[i];
  }

  cout << numberOfAlternatingGroups(colors, k) << endl;
}

int main()
{
  solution();

  return 0;
}
