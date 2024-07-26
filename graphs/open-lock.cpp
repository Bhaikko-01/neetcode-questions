/**
 * 1. BFS
 *      Use BFS where neighbor nodes will be getting prev and next of each index
 *        of currNode
 *      Keep track of visited nodes in same deadendMapping because it means same
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> getAdjacentNeighbours(string& currLock, int index)
{
  int num = stoi(currLock.substr(index, 1));

  int prev = num == 0 ? 9 : num - 1;
  string prevString = string(currLock);
  prevString[index] = to_string(prev)[0];

  int next = num == 9 ? 0 : num + 1;
  string nextString = string(currLock);
  nextString[index] = to_string(next)[0];

  return { prevString, nextString };
}

vector<string> getNeighbours(string& currLock)
{
  vector<string> neighbours;

  int n = currLock.size();
  for (int i = 0; i < currLock.size(); i++) {
    vector<string> adjacentNeighbors = getAdjacentNeighbours(currLock, i);
    neighbours.insert(neighbours.end(), adjacentNeighbors.begin(), adjacentNeighbors.end());
  }

  return neighbours;
}

int openLock(vector<string>& deadends, string target)
{
  unordered_map<string, bool> deadendMapping;
  for (string s: deadends) {
    deadendMapping[s] = true;
  }

  string currLock = "0000";
  int count = 0;

  queue<string> pending;

  if (!deadendMapping[currLock]) {
    pending.push(currLock);
  }

  while (!pending.empty()) {
    int currSize = pending.size();

    for (int i = 0; i < currSize; i++) {
      string currString = pending.front();
      pending.pop();

      if (currString == target) {
        return count;
      }

      vector<string> neighbors = getNeighbours(currString);
      for (string neighbor: neighbors) {
        if (!deadendMapping[neighbor]) {
          pending.push(neighbor);
        }

        deadendMapping[neighbor] = true;
      }
    }

    count++;
  }

  return -1;
}

void solution()
{
  int n;
  cin >> n;

  vector<string> deadends(n);
  for (int i = 0; i < n; i++) {
    cin >> deadends[i];
  }

  string target;
  cin >> target;

  cout << openLock(deadends, target) << endl;
}

int main()
{
  solution();

  return 0;
}
