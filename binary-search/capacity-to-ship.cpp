#include <bits/stdc++.h>

using namespace std;

int shipWithinDays(vector<int>& weights, int days)
{
  int n = weights.size();

  int sum = 0;
  for (int x: weights) {
    sum += x;
  }

  int l = 1,
      r = sum;

  int minAns = sum;

  while (l <= r) {
    int currCapacity = (l + r) / 2;

    int currDays = 1;
    int sumWeight = 0;

    for (int weight: weights) {
      if (weight > currCapacity) {
        currDays = INT_MAX;
        break;
      }

      sumWeight += weight;

      if (sumWeight > currCapacity) {
        currDays++;
        sumWeight = weight;
      }
    }

    if (currDays <= days) {
      minAns = min(minAns, currCapacity);

      r = currCapacity - 1;
    } else {
      l = currCapacity + 1;
    }
  }

  return minAns;
}

void solution()
{
  int n, days;
  cin >> n >> days;

  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> weights[i];
  }

  cout << shipWithinDays(weights, days) << endl;
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
