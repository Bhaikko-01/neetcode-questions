/**
 * 1. BruteForce - O(2*n^2*m)
 *      Create adjacency list from wordlist - O(n^2m), m is length of each word
 *      Run BFS to find shortest path
 *        Weight of each edge is 1 so BFS can be used
 * 2. Optmise adjacency list contruction - O(n*m^2) + O(n^2*m)
 *      Instead of having word as node, generate patterns of a word and make that as graph node
 *        that pattern will have all the words from which it can be obtained
 *          hot -> [*ot, h*t, ho*] patterns and each pattern will be node in adjacency list
 *      For getting neighbors of word,
 *        generate all patterns and combine all words obtained from it
 *        make sure current word in not included in neighbors
 *      BFS using this graph using beginWord until endWord is found
 *      Graph Data Structure -> unordered_map<string, set<string>> graph
*/
#include <bits/stdc++.h>

using namespace std;

// ! 1.
bool isOneDiffer(string& first, string& second)
{
  if (first.length() != second.length()) {
    return false;
  }

  bool diffFound = false;

  for (int i = 0; i < first.size(); i++) {
    if (first[i] != second[i]) {
      if (diffFound) {
        return false;
      } else {
        diffFound = true;
      }
    }
  }

  return true;
}

// ! 1.
int ladderLengthBrute(string beginWord, string endWord, vector<string>& wordList)
{
  int n = wordList.size();

  unordered_map<string, vector<string>> graph;
  bool isBeingWordInList = false;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (isOneDiffer(wordList[i], wordList[j])) {
        graph[wordList[i]].push_back(wordList[j]);
      }
    }

    if (beginWord == wordList[i]) {
      isBeingWordInList = true;
    }
  }


  if (!isBeingWordInList) {
    for (int i = 0; i < n; i++) {
      if (isOneDiffer(beginWord, wordList[i])) {
        graph[beginWord].push_back(wordList[i]);
      }
    }
  }

  unordered_map<string, bool> visited;
  queue<string> pending;
  int count = 0;

  pending.push(beginWord);
  visited[beginWord] = true;

  while (!pending.empty()) {
    int queueSize = pending.size();

    for (int i = 0; i < queueSize; i++) {
      string curr = pending.front();
      pending.pop();

      for (string neighbor: graph[curr]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;

          if (neighbor == endWord) {
            return count + 1;
          }

          pending.push(neighbor);
        }
      }
    }

    count++;
  }

  return 0;
}

// ! 2.
vector<string> generatePatterns(string& word)
{
  int n = word.size();
  vector<string> patterns;

  for (int i = 0; i < n; i++) {
    patterns.push_back(word.substr(0, i) + "*" + word.substr(i + 1, n - i));
  }

  return patterns;
}

// ! 2.
unordered_map<string, set<string>> generateAdjacencyListGraph(vector<string>& wordList)
{
  int n = wordList.size();
  unordered_map<string, set<string>> graph;

  for (string word: wordList) {
    vector<string> patterns = generatePatterns(word);

    for (string pattern: patterns) {
      graph[pattern].insert(word);
    }
  }

  return graph;
}

// ! 2.
set<string> getNeighborsByPatterns(unordered_map<string, set<string>>& graph, string& node)
{
  vector<string> patterns = generatePatterns(node);

  set<string> neighbors;
  for (string pattern: patterns) {
    for (string word: graph[pattern]) {
      if (word != node) {
        neighbors.insert(word);
      }
    }
  }

  return neighbors;
}

// ! 2.
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
  int n = wordList.size();

  vector<string>::iterator beginWordIterator = find(wordList.begin(), wordList.end(), beginWord);
  if (beginWordIterator == wordList.end()) {
    wordList.push_back(beginWord);
  }

  unordered_map<string, set<string>> graph = generateAdjacencyListGraph(wordList);

  queue<string> pending;
  pending.push(beginWord);

  unordered_map<string, bool> visited;

  int count = 0;

  while (!pending.empty()) {
    int currElements = pending.size();

    for (int i = 1; i <= currElements; i++) {
      string curr = pending.front();
      pending.pop();

      if (curr == endWord) {
        return count + 1;
      }

      set<string> neighbors = getNeighborsByPatterns(graph, curr);

      for (string neighbor: neighbors) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;

          pending.push(neighbor);
        }
      }
    }

    count++;
  }

  return 0;
}

void solution()
{
  int n;
  cin >> n;

  string beginWord, endWord;
  cin >> beginWord >> endWord;

  vector<string> wordList(n);
  for (int i = 0; i < n; i++) {
    cin >> wordList[i];
  }

  cout << ladderLength(beginWord, endWord, wordList) << endl;
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
