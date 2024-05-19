#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

int findRotateSteps(string& ring, string& key, int currPosInDial, int currIndex, unordered_map<string, int>& occured)
{
  int n = ring.size();

  string dpKey = getKey(currPosInDial, currIndex);

  if (occured.find(dpKey) != occured.end()) {
    return occured[dpKey];
  }

  if (currIndex == key.size()) {
    return 0;
  }

  int leftIndex = currPosInDial;
  int leftSteps = 0;
  while (ring[leftIndex] != key[currIndex]) {
    leftIndex = leftIndex - 1 >= 0 ? leftIndex - 1 : n - 1;
    leftSteps++;
  }

  int rightIndex = currPosInDial;
  int rightSteps = 0;
  while (ring[rightIndex] != key[currIndex]) {
    rightIndex = (rightIndex + 1) % n;
    rightSteps++;
  }

  int stepsIfWentLeft = findRotateSteps(ring, key, leftIndex, currIndex + 1, occured) + leftSteps;
  int stepsIfWentRight = findRotateSteps(ring, key, rightIndex, currIndex + 1, occured) + rightSteps;

  occured[dpKey] = min(stepsIfWentLeft, stepsIfWentRight) + 1;

  return occured[dpKey];
}

int findRotateSteps(string ring, string key)
{
  unordered_map<string, int> occured;

  return findRotateSteps(ring, key, 0, 0, occured);
}

void solution()
{
  string ring, key;
  cin >> ring >> key;

  cout << findRotateSteps(ring, key) << endl;
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
