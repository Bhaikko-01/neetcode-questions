#include <bits/stdc++.h>

using namespace std;

std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> result;
  std::string current;

  for (char c : s) {
    if (c == delim) {
      result.push_back(current);
      current.clear();
    } else {
      current += c;
    }
  }

  result.push_back(current);

  return result;
}

bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2)
{
  int n = sentence1.size();
  int m = sentence2.size();

  int l = -1,
      r = n;

  for (int i = 0; i < n; i++) {
    if (sentence1[i] != sentence2[i]) {
      break;
    }

    l = i;
  }

  int sen1Index = n - 1;
  for (int i = m - 1; i > l && sen1Index >= 0; i--) {
    if (sentence1[sen1Index] != sentence2[i]) {
      break;
    }

    r = sen1Index;
    sen1Index--;
  }

  return (r - l) <= 1;
}

bool areSentencesSimilar(string sentence1, string sentence2)
{
  vector<string> sentence1Separated = split(sentence1, ' ');
  vector<string> sentence2Separated = split(sentence2, ' ');

  int n = sentence1Separated.size(),
      m = sentence2Separated.size();

  if (n < m) {
    return areSentencesSimilar(sentence1Separated, sentence2Separated);
  }

  return areSentencesSimilar(sentence2Separated, sentence1Separated);
}

void solution()
{
  string sentence2 = "Hello Jane";
  string sentence1 = "Hello my name is Jane";
  // cout << areSentencesSimilar(sentence1, sentence2) << endl;

  // sentence2 = "of";
  // sentence1 = "A lot of words";
  // cout << areSentencesSimilar(sentence1, sentence2) << endl;

  // sentence2 = "Eating right now";
  // sentence1 = "Eating";
  // cout << areSentencesSimilar(sentence1, sentence2) << endl;

  sentence2 = "xD iP tqchblXgqvNVdi";
  sentence1 = "FmtdCzv Gp YZf UYJ xD iP tqchblXgqvNVdi";
  cout << areSentencesSimilar(sentence1, sentence2) << endl;

}

int main()
{
  solution();

  return 0;
}
