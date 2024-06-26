#include <bits/stdc++.h>

using namespace std;

int numRescueBoats(vector<int>& people, int limit)
{
  int n = people.size();

  sort(people.begin(), people.end());

  int boatsUsed = 0;

  int l = 0, r = n - 1;

  while (l <= r) {
    if (l == r) {
      boatsUsed++;
      break;
    }

    int remainWeight = limit - people[l];

    while (r > l && people[r] > remainWeight) {
      boatsUsed++;
      r--;
    }

    boatsUsed++;
    l++;
    r--;
  }

  return boatsUsed;
}

void solution()
{
  int n, limit;
  cin >> n >> limit;

  vector<int> people(n);

  for (int i = 0; i < n; i++) {
    cin >> people[i];
  }

  cout << numRescueBoats(people, limit) << endl;
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
