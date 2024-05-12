/**
 * 1. Brute force - O(n^2) [T]
 *      For every index, check if cycle can be created and same index can be reached
 *        based on currGas
 *      At each index, currGas += (gas[i] - cost[i])
 *        If currGas < 0 then not possible
 *        Else continue cycle
 * 2. Greedy - O(n) [T + S]
 *      If gasSpent <= gasAdded then surely there is an answer
 *      Maintain deltaGas array containing gas[i] = cost[i]
 *        negative value indicates more gas was used then added therefore cannot be used as start.
 *        These are never considered for answer
 *      To find ans, find an index which provides a positive sum till last element is reached
 *        this works because if such an index exists then it can complete cycle to its right
 *        since, we are assure that ans exist, this index is answer
 *      If sum reaches zero, we reset sum and set index to next value as that might be answer
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1.
bool tryCycle(vector<int>& gas, vector<int>& cost, int i)
{
  int n = gas.size();
  int endIndex = i;
  int currGas = 0;

  while (true) {
    currGas += gas[i];
    currGas -= cost[i];

    if (currGas < 0) {
      return false;
    }

    i = (i + 1) % n;

    if (i == endIndex) {
      return true;
    }
  }
}

// ! 1.
int canCompleteCircuitBrute(vector<int>& gas, vector<int>& cost)
{
  int n = gas.size();

  for (int i = 0; i < n; i++) {
    if (tryCycle(gas, cost, i)) {
      return i;
    }
  }

  return -1;
}

// ! 2.
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
  int n = gas.size();

  int gasSpent = 0,
      gasAdded = 0;

  for (int i = 0; i < n; i++) {
    gasSpent += cost[i];
    gasAdded += gas[i];
  }

  if (gasSpent > gasAdded) {
    return -1;
  }

  vector<int> deltaGas(n);
  for (int i = 0; i < n; i++) {
    deltaGas[i] = gas[i] - cost[i];
  }

  int sum = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    sum += deltaGas[i];

    if (sum < 0) {
      sum = 0;
      ans = i + 1;
    }
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> gas(n), cost(n);
  for (int i = 0; i < n; i++) {
    cin >> gas[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  cout << canCompleteCircuit(gas, cost) << endl;
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
