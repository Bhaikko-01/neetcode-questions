/**
 * 1. Bruteforce - O(n + n^2 + nk) ~ O(n^2) [T], O(n) [S]
 *      Create groups and return answer based on that
 *      If n is not divisble by groupSize then groups can never be created
 *      Maintain unordered_map to store occurence of each number.
 *      Run iterations till map is empty
 *        get minElement from map as that will be group starter
 *        Find successive elements of minElement and decrease occurence as group is created
 *        If successive not found then group not possible, return false
 *        Else decrease occurence and delete if occurence is zero
*/

#include <bits/stdc++.h>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize)
{
  int n = hand.size();

  if (n % groupSize != 0) {
    return false;
  }

  unordered_map<int, int> occurences;
  // O(n)
  for (int x: hand) {
    occurences[x]++;
  }

  // O(n)
  while (!occurences.empty()) {
    int groupStart = INT_MAX;

    // O(n)
    for (auto x: occurences) {
      groupStart = min(groupStart, x.first);
    }

    // O(k)
    for (int i = 1; i <= groupSize; i++) {
      auto occurenceIteratorForGroupStart = occurences.find(groupStart);

      if (occurenceIteratorForGroupStart == occurences.end()) {
        return false;
      }

      occurences[groupStart]--;

      if (occurences[groupStart] == 0) {
        occurences.erase(occurenceIteratorForGroupStart);
      }

      groupStart++;
    }
  }

  return true;
}

void solution()
{
  int n, groupSize;
  cin >> n >> groupSize;

  vector<int> hand(n);
  for (int i = 0; i < n; i++) {
    cin >> hand[i];
  }

  cout << isNStraightHand(hand, groupSize) << endl;
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
