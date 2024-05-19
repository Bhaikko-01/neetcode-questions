#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int numOfSubarrays(vector<int>& arr, int k, int threshold)
{
  int n = arr.size();

  int l = 0,
      r = k - 1;

  int count = 0;

  ll sum = 0;

  for (int i = 0; i < k - 1; i++) {
    sum += arr[i];
  }

  double avg = 0;

  while (r < n) {
    sum += arr[r];

    avg = sum / (k * 1.0);

    if (avg >= threshold) {
      count++;
    }

    sum -= arr[l];

    l++;
    r++;
  }

  return count;
}

void solution()
{
  int n, k, threshold;
  cin >> n >> k >> threshold;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << numOfSubarrays(arr, k, threshold) << endl;
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
