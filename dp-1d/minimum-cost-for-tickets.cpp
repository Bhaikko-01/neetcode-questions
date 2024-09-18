#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

int mincostTickets(vector<int>& days, int currIndex, int allowedDay, vector<int>& costs, unordered_map<string, int>& dp)
{
  int n = days.size();
  string key = getKey(currIndex, allowedDay);

  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  if (currIndex >= n) {
    return 0;
  }

  if (days[currIndex] <= allowedDay) {
    return mincostTickets(days, currIndex + 1, allowedDay, costs, dp);
  }

  int day1Bought  = mincostTickets(days, currIndex + 1, days[currIndex] + 0, costs, dp) + costs[0];
  int day7Bought  = mincostTickets(days, currIndex + 1, days[currIndex] + 6, costs, dp) + costs[1];
  int day30Bought = mincostTickets(days, currIndex + 1, days[currIndex] + 29, costs, dp) + costs[2];

  dp[key] = min(day1Bought, min(day7Bought, day30Bought));

  return dp[key];
}

int mincostTickets(vector<int>& days, vector<int>& costs)
{
  unordered_map<string, int> dp;
  return mincostTickets(days, 0, 0, costs, dp);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> days(n);
  for (int i = 0; i < n; i++) {
    cin >> days[i];
  }

  vector<int> costs(3);
  cin >> costs[0] >> costs[1] >> costs[2];

  cout << mincostTickets(days, costs) << endl;
}

int main()
{
  solution();

  return 0;
}
