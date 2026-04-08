#include <bits/stdc++.h>

using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
{
  int n = customers.size();

  int answer = 0;

  for (int i = 0; i < n; i++) {
    if (grumpy[i] == 0) {
      answer += customers[i];
    }
  }

  int l = 0, r = minutes - 1;

  for (int i = 0; i < minutes - 1; i++) {
    if (grumpy[i] == 1) {
      answer += customers[i];
    }
  }

  int currAns = answer;

  while (r < n) {
    if (grumpy[r] == 1) {
      currAns += customers[r];
    }

    answer = max(answer, currAns);

    if (grumpy[l] == 1) {
      currAns -= customers[l];
    }

    l++;
    r++;
  }

  return answer;
}

void solution()
{
  int n, minutes;
  cin >> n >> minutes;

  vector<int> customers(n), grumpy(n);

  for (int i = 0; i < n; i++) {
    cin >> customers[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> grumpy[i];
  }

  cout << maxSatisfied(customers, grumpy, minutes) << endl;
}

int main()
{
  solution();

  return 0;
}
