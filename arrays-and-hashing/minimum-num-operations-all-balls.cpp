#include <bits/stdc++.h>

using namespace std;

vector<int> minOperations(string boxes)
{
  int n = boxes.size();

  vector<int> ans;

  for (int i = 0; i < n; i++) {
    int moves = 0;

    // Right
    for (int j = i + 1; j < n; j++) {
      if (boxes[j] == '1') {
        moves += (j - i);
      }
    }

    // Left
    for (int j = i -1; j >= 0; j--) {
      if (boxes[j] == '1') {
        moves += (i - j);
      }
    }

    ans.push_back(moves);
  }

  return ans;
}

void solution()
{
  string boxes;
  cin >> boxes;

  vector<int> ans = minOperations(boxes);

  for (int x: ans) {
    cout << x << " ";
  }

  cout << endl;
}

int main()
{
  solution();

  return 0;
}
