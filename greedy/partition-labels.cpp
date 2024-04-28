/**
 * 1. Greedy - O(n) [T], O(n) [S]
 *      Maintain hash where each element occuredLast in string
 *      Maintain hash tracking which elements have occured till now - occuredTillNow
 *      In each iteration,
 *        check if current element occurs in future,
 *        If yes, continue and put this in already occured element
 *        Else,
 *          check already occured elements using occuredTillNow hash occur in future, - O(26)
 *          If occur, continue and put this in already occured
 *          Else
 *            count till now is answer for current index, push that and clear occuredTillNow hash
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> partitionLabels(string s)
{
  int n = s.size();

  unordered_map<char, int> lastIndexOccurence;
  unordered_map<char, bool> occuredTillNow;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    lastIndexOccurence[s[i]] = i;
  }

  int currParitionLength = 0;

  // ! O(n)
  for (int i = 0; i < n; i++) {
    char currChar = s[i];

    if (lastIndexOccurence[currChar] > i) {
      occuredTillNow[currChar] = true;
      currParitionLength++;
    } else {

      // ! O(26), since only lowercase english letters allowed
      bool prevElFound = false;
      for (auto x: occuredTillNow) {
        if (lastIndexOccurence[x.first] > i) {
          prevElFound = true;
          currParitionLength++;
          break;
        }
      }

      if (!prevElFound) {
        ans.push_back(currParitionLength + 1);
        currParitionLength = 0;
        occuredTillNow.clear();
      } else {
        occuredTillNow[currChar] = true;
      }
    }
  }

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  vector<int> ans = partitionLabels(s);

  for (int x: ans) {
    cout << x << " ";
  }
  cout << endl;
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
