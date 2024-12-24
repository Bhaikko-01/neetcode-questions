/**
 * 1. Binary Search - O(nlogn)
 *      For every prefix in searchWord, get leftMost element in products array
 *      Sort products array and use Binary search
 *        If mid element matches as prefix in currWord, then its possible leftMost element
 *        Search in left subArray if mid element is lexo smaller than mid
 *        Else search in write
 *      Binary Search will return leftMost element,
 *        Try for 3 elements from that index if those match the current prefix
 */

#include <bits/stdc++.h>

using namespace std;

bool containsPrefix(string& word, string prefix)
{
  string wordPrefix = word.substr(0, prefix.size());

  return wordPrefix == prefix;
}

int getPrefixMatchingIndex(vector<string>& products, string prefix)
{
  int n = products.size();

  int l = 0,
      r = n - 1;

  int index = -1;

  while (l <= r) {
    int mid = (l + r) / 2;

    string word = products[mid];
    if (containsPrefix(word, prefix)) {
      index = mid;
    }

    if (prefix <= word) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return index;
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
{
  int n = products.size();
  int m = searchWord.size();

  sort(products.begin(), products.end());

  vector<vector<string>> ans;

  for (int size = 1; size <= m; size++) {
    string prefix = searchWord.substr(0, size);

    int prefixMatchingIndex = getPrefixMatchingIndex(products, prefix);

    vector<string> currPrefixAns;

    if (prefixMatchingIndex != -1) {
      for (int i = prefixMatchingIndex; i < n; i++) {
        if (currPrefixAns.size() == 3) {
          break;
        }

        string currWord = products[i];
        if (containsPrefix(currWord, prefix)) {
          currPrefixAns.push_back(currWord);
        } else {
          break;
        }
      }
    }

    ans.push_back(currPrefixAns);
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<string> products(n);
  for (int i = 0; i < n; i++) {
    cin >> products[i];
  }

  string searchWord;
  cin >> searchWord;

  vector<vector<string>> ans = suggestedProducts(products, searchWord);

  for (auto x: ans) {
    for (auto y: x) {
      cout << y << " ";
    }

    cout << endl;
  }
}

int main()
{
  solution();

  return 0;
}

/*
5
mobile mouse moneypot monitor mousepad
mouse

5
bags baggage banner box cloths
bags
*/
