#include <bits/stdc++.h>

using namespace std;

bool isValidOctet(string s)
{
  if (s.length() == 1) {
    return true;
  }

  if (s[0] == '0') {
    return false;
  }

  int num = stoi(s);

  return num >= 0 && num <= 255;
}

void restoreIpAddresses(string s, int currIndex, int octetsCreated, string currIp, vector<string>& ans)
{
  int n = s.size();

  if (currIndex >= n) {
    if (octetsCreated == 4) {
      ans.push_back(currIp);
    }

    return;
  }

  if (octetsCreated >= 4) {
    return;
  }

  for (int len = 1; len <= 3 && currIndex + len <= n; len++) {
    string octet = s.substr(currIndex, len);

    if (isValidOctet(octet)) {
      string newIp = currIp.length() ? currIp + "." + octet : octet;

      restoreIpAddresses(s, currIndex + len, octetsCreated + 1, newIp, ans);
    }
  }
}

vector<string> restoreIpAddresses(string s)
{
  vector<string> ans;
  string currIp;

  restoreIpAddresses(s, 0, 0, currIp, ans);

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  vector<string> ips = restoreIpAddresses(s);

  for (string s: ips) {
    cout << s << endl;
  }
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
