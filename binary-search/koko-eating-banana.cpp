/**
 * 1. Bruteforce - O(n^2)
 *    Need to "search" minimum speed which satisfies a condition
 *    Speed bounds will be 1 to maxElement(piles)
 *    Condition is to eat bananas under specific hour
 *      totalHourSpent = (hours += piles[i] / speed + (piles[i] % speed ? 1 : 0))
 *    First speed that satisfies hour condition is answer
 *      No need to check further as "speed" is searched min to max
 * 2. Binary Search - O(nlogn)
 *    Search minimum "speed" using binary search
 *    Bound: 1 to maxElement(piles)
 *    Binary Search like this
 *      currSpeed = (l + r) / 2;
 *      if currSpeed <= h -> better answer may exist in left part
 *        r = currSpeed - 1
 *        minSpeed = min(minSpeed, currSpeed)  // As we search in right bound, currSpeed may be more than minSpeed
 *      else -> No answer found so dont consider speed less than curr
 *        l = currSpeed + 1
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ! 1.
int minEatingSpeedBrute(vector<int>& piles, int h)
{
  int n = piles.size();

  ll l = 1, r = *max_element(piles.begin(), piles.end());

  for (ll speed = l; speed <= r; speed++) {
    ll hours = 0;

    for (int bananas: piles) {
      hours += (bananas / speed) + (bananas % speed ? 1 : 0);
    }

    if (hours <= h) {
      return speed;
    }
  }

  return 0;
}

// ! 2.
int minEatingSpeed(vector<int>& piles, int h)
{
  int n = piles.size();
  ll minSpeed = LLONG_MAX;

  ll l = 1, r = *max_element(piles.begin(), piles.end());

  while (l <= r) {
    ll currSpeed = (l + r) / 2;
    ll hours = 0;

    for (int bananas: piles) {
      hours += (bananas / currSpeed) + (bananas % currSpeed ? 1 : 0);
    }

    if (hours <= h) {
      r = currSpeed - 1;
      minSpeed = min(minSpeed, currSpeed);
    } else {
      l = currSpeed + 1;
    }
  }

  return minSpeed;
}

void solution()
{
  int n, h;
  cin >> n >> h;

  vector<int> piles(n);
  for (int i = 0; i < n; i++) {
    cin >> piles[i];
  }

  cout << minEatingSpeed(piles, h) << endl;
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
