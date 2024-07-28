/**
 * 1. Iterative - O(n)
 *      Maintain mapping of direct and indirect conversions
 *      Reduce num till not zero
 *      Divide by mapping number to get prefex and append symbol the quiotent times
 *      Reduce number by modulo
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> intStringPair;

vector<intStringPair> intToRomanMapping = {
  { 1, "I" },
  { 4, "IV" },
  { 5, "V" },
  { 9, "IX" },
  { 10, "X" },
  { 40, "XL" },
  { 50, "L" },
  { 90, "XC" },
  { 100, "C" },
  { 400, "CD" },
  { 500, "D" },
  { 900, "CM" },
  { 1000, "M" },
};

string intToRoman(int num)
{
  int mappingIndex = intToRomanMapping.size() - 1;

  string ans = "";

  while (num != 0) {
    intStringPair currPair = intToRomanMapping[mappingIndex--];

    int prefix = num / currPair.first;

    for (int i = 1; i <= prefix; i++) {
      ans += currPair.second;
    }

    num = num % currPair.first;
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  cout << intToRoman(n) << endl;
}

int main()
{
  solution();

  return 0;
}
