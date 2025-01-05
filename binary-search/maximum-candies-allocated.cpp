/**
 * 1. Binary search - O(nlogn)
 *      Same as Koko eating banana
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int maximumCandies(vector<int>& candies, long long k)
{
  int maxPile = *max_element(candies.begin(), candies.end());

  int maxCandies = 0;
  int l = 0,
      r = maxPile;
  int n = candies.size();

  while (l <= r) {
    int mid = (l + r) / 2;

    ll childSatisfied = 0;

    if (mid == 0) {
      childSatisfied = k;
    } else {
      for (int i = 0; i < n; i++) {
        childSatisfied += (ll)(candies[i] / mid);
      }
    }

    if (childSatisfied >= k) {
      l = mid + 1;
      maxCandies = max(maxCandies, mid);
    } else {
      r = mid - 1;
    }
  }

  return maxCandies;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> candies(n);
  for (int i = 0; i < n; i++) {
    cin >> candies[i];
  }

  cout << maximumCandies(candies, k) << endl;
}

int main()
{
  solution();

  return 0;
}
