#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input)
{
  vector<string> spitted;

  int l = 0;
  int n = input.size();

  for (int i = 0; i < n; i++) {
    if (input[i] == '/') {
      if (i - l > 0) {
        spitted.push_back(input.substr(l, i - l));
      }

      l = i + 1;
    }
  }

  if (n - l > 0) {
    spitted.push_back(input.substr(l, n - l));
  }

  return spitted;
}

string simplifyPath(string path)
{
  int n = path.size();

  vector<string> splittedPaths = split(path);
  stack<string> pending;

  for (string x: splittedPaths) {
    if (x == "..") {
      if (!pending.empty()) {
        pending.pop();
      }
    } else if (x != ".") {
      pending.push(x);
    }
  }

  string ans = "";
  while (!pending.empty()) {
    string top = pending.top();

    ans = "/" + top + ans;
    pending.pop();
  }

  if (ans.length() == 0) {
    return "/";
  }

  return ans;
}

void solution()
{
  string path;
  cin >> path;

  cout << simplifyPath(path) << endl;
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
