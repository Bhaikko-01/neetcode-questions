/**
 * Possible approaches
 * 1. Brute force - O(n^2 * m^2), n are number of elements, m is length of string
 *    Check anagrams pairs and add them to a Set
 *    Print each set in the end
 *    Optimisation can be done here if a string is already anagram
 * 2. Sort all strings and check how many are equal - O(n * mlogm)
 * 3. Generate unique key for each element and group based on that - O(n * m)
 */

#include <bits/stdc++.h>

using namespace std;

// ! 1.
bool isAnagram(string s, string t)
{
  unordered_map<char, int> s_occurences;

  if (s.length() != t.length()) {
    return false;
  }

  for (int i = 0; i < s.length(); i++) {
    s_occurences[s[i]]++;
  }

  for (int i = 0; i < t.length(); i++) {
    s_occurences[t[i]]--;

    if (s_occurences[t[i]] < 0) {
      return false;
    }
  }

  for (unordered_map<char, int>::iterator it = s_occurences.begin(); it != s_occurences.end(); it++) {
    if (it->second != 0) {
      return false;
    }
  }

  return true;
}

// ! 1.
vector<vector<string>> groupAnagramsBruteForce(vector<string>& strs)
{
  int n = strs.size();

  typedef unordered_map<int, bool> intMapping;

  vector<intMapping> occuredAnagramsMapping;
  intMapping occuredAnagrams;

  // 10^4 * 10^4 * 10^2 = 10^10
  for (int i = 0; i < n; i++) {
    if (occuredAnagrams[i]) {
      continue;
    }

    intMapping mapping;

    bool anagramFound = false;

    for (int j = i + 1; j < n; j++) {
      if (occuredAnagrams[j]) {
        continue;
      }

      if (isAnagram(strs[i], strs[j])) {
        anagramFound = true;

        occuredAnagrams[i] = true;
        occuredAnagrams[j] = true;

        mapping[i] = true;
        mapping[j] = true;
      }
    }

    if (!anagramFound) {
      mapping[i] = true;
    }

    occuredAnagramsMapping.push_back(mapping);
  }

  vector<vector<string>> ans;

  for (intMapping currMap: occuredAnagramsMapping) {
    vector<string> currAns;

    for (intMapping::iterator it = currMap.begin(); it != currMap.end(); it++) {
      currAns.push_back(strs[it->first]);
    }

    ans.push_back(currAns);
  }

  return ans;
}

// ! 3.
string generateKeyForWord(string& word)
{
  int hashes[26] = { 0 };

  for (int i = 0; i < word.length(); i++) {
    int asciiVal = (int)word[i] - 97;
    hashes[asciiVal]++;
  }

  string key = "";
  for (int i = 0; i < 26; i++) {
    if (hashes[i]) {
      key += ((char)(i + 97) + to_string(hashes[i]));
    }
  }

  return key;
}

// ! 3.
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
  int n = strs.size();

  unordered_map<string, vector<string>> groupedAnagramsByKey;

  for (string word: strs) {
    string currentKey = generateKeyForWord(word);

    if (groupedAnagramsByKey.find(currentKey) == groupedAnagramsByKey.end()) {
      groupedAnagramsByKey[currentKey] = vector<string>();
    }

    groupedAnagramsByKey[currentKey].push_back(word);
  }

  vector<vector<string>> ans;

  for (unordered_map<string, vector<string>>::iterator it = groupedAnagramsByKey.begin(); it != groupedAnagramsByKey.end(); it++) {
    ans.push_back(it->second);
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<string> strs(n);
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
  }

  vector<vector<string>> ans = groupAnagrams(strs);

  for (vector<string> i: ans) {
    for (string j: i) {
      cout << j << " ";
    }
    cout << endl;
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
