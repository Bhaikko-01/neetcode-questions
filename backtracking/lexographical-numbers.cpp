#include <bits/stdc++.h>

using namespace std;

vector<int> lexicalOrder(int n, int currNum)
{
  vector<int> currNums;

  for (int i = 0; i <= 9; i++) {
    int numToPush = currNum * 10 + i;

    if (numToPush != 0 && numToPush <= n) {
      currNums.push_back(numToPush);

      vector<int> lexical = lexicalOrder(n, numToPush);
      currNums.insert(currNums.end(), lexical.begin(), lexical.end());
    }
  }

  return currNums;
}

vector<int> lexicalOrder(int n)
{
  return lexicalOrder(n, 0);
}

void solution()
{
  int n;
  cin >> n;

  vector<int> ans = lexicalOrder(n);

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
