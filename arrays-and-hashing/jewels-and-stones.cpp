#include <bits/stdc++.h>

using namespace std;

int numJewelsInStones(string jewels, string stones)
{
  unordered_map<char, bool> jewelsMapping;
  for (char a: jewels) {
    jewelsMapping[a] = true;
  }

  int count = 0;
  for (char x: stones) {
    if (jewelsMapping[x]) {
      count++;
    }
  }

  return count;
}

void solution()
{
  string jewels, stones;
  cin >> jewels >> stones;

  cout << numJewelsInStones(jewels, stones) << endl;
}

int main()
{
  solution();

  return 0;
}
