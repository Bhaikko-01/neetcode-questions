#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
  int n = spells.size();
  int m = potions.size();

  vector<int> ans;

  sort(potions.begin(), potions.end());

  for (int i = 0; i < n; i++) {
    int spell = spells[i];

    int l = 0, r = m - 1;
    int minIndex = INT_MAX;

    while (l <= r) {
      int mid = (l + r) / 2;

      ll product = potions[mid] * (ll)spell;

      if (product >= success) {
        minIndex = min(minIndex, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    if (minIndex == INT_MAX) {
      ans.push_back(0);
    } else {
      ans.push_back(m - minIndex);
    }
  }

  return ans;
}

void solution()
{
  int n, m, success;
  cin >> n >> m >> success;

  vector<int> spells(n), potions(m);
  for (int i = 0; i < n; i++) {
    cin >> spells[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> potions[i];
  }

  vector<int> ans = successfulPairs(spells, potions, success);
  for (int num: ans) {
    cout << num << " ";
  }
  cout << endl;
}

int main()
{
  solution();

  return 0;
}
