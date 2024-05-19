#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  int incrementalId = 1;
  unordered_map<string, string> mapping;
private:
  string getId()
  {
    string id = to_string(incrementalId);
    incrementalId++;
    return id;
  }

  int getPathIndex(string url)
  {
    int pathSlashCount = 0;

    int n = url.size();
    for (int i = 0; i < n; i++) {
      if (url[i] == '/') {
        pathSlashCount++;
      }

      if (pathSlashCount == 3) {
        return i;
      }
    }

    return -1;
  }

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
      string id = getId();
      mapping[id] = longUrl;

      return "http://tinyurl.com/" + id;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
      int pathSlashIndex = getPathIndex(shortUrl);

      cout << shortUrl.substr(pathSlashIndex + 1) << endl;;

      return mapping[shortUrl.substr(pathSlashIndex + 1)];
    }
};

void solution()
{
  string url;
  cin >> url;

  Solution solutionObj;
  string shortened = solutionObj.encode(url);
  cout << shortened << endl;

  string decoded = solutionObj.decode(shortened);
  cout << decoded << endl;
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
