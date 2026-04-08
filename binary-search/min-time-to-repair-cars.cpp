#include <bits/stdc++.h>

using namespace std;

using ll = long long;

inline ll repairCost(int rank, int cars) {
  return (ll)rank * (ll)cars * (ll)cars;
}

long long repairCars(vector<int>& ranks, int cars)
{
  int n = ranks.size();

  ll maxMinutes = 0;
  for (int rank: ranks) {
    maxMinutes = max(maxMinutes, repairCost(rank, cars));
  }

  double rhs = cars;

  // * Brute Force
  // for (ll currMin = 1; currMin <= maxMinutes; currMin++) {
  //   ll lhs = 0;

  //   for (int rank: ranks) {
  //     lhs += floor((sqrt(currMin / rank)));
  //   }
  //   if (lhs >= rhs) {
  //     return currMin;
  //   }
  // }

  ll l = 0, r = maxMinutes;
  ll ans = LLONG_MAX;

  // * Binary Search
  while (l <= r) {
    ll currMin = (l + r) / 2;

    ll lhs = 0;

    for (int rank: ranks) {
      lhs += floor((sqrt(currMin / rank)));
    }

    // cout << lhs << " " << rhs << " " << currMin << endl;

    if (lhs >= rhs) {
      ans = min(ans, currMin);
      r = currMin - 1;
    } else {
      l = currMin + 1;
    }
  }

  return ans;
}

void solution()
{
  int n, cars;
  cin >> n >> cars;

  vector<int> ranks(n);

  for (int i = 0; i < n; i++) {
    cin >> ranks[i];
  }

  cout << repairCars(ranks, cars) << endl;
}

int main()
{
  solution();

  return 0;
}
