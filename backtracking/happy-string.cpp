/**
 * WRITE EXPLAINATION
 */

#include <bits/stdc++.h>

using namespace std;

void getHappyString(int i, string s, int n, int& k, string& ans)
{
  if (i == n - 1) {
    k--;

    if (k == 0) {
      ans = s;
    }

    return;
  }

  if (i == -1) {
    getHappyString(i + 1, s + "a", n, k, ans);
    getHappyString(i + 1, s + "b", n, k, ans);
    getHappyString(i + 1, s + "c", n, k, ans);
  } else if (s[i] == 'a') {
    getHappyString(i + 1, s + "b", n, k, ans);
    getHappyString(i + 1, s + "c", n, k, ans);
  } else if (s[i] == 'b') {
    getHappyString(i + 1, s + "a", n, k, ans);
    getHappyString(i + 1, s + "c", n, k, ans);
  } else if (s[i] == 'c') {
    getHappyString(i + 1, s + "a", n, k, ans);
    getHappyString(i + 1, s + "b", n, k, ans);
  }
}

string getHappyString(int n, int k)
{
  string s = "";
  string ans = "";

  getHappyString(-1, s, n, k, ans);

  return ans;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  cout << getHappyString(n, k) << endl;
}

int main()
{
  solution();

  return 0;
}
