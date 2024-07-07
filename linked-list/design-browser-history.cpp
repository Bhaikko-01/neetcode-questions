#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  string url;
  Node *left;
  Node *right;

public:
  Node(string url)
  {
    this->url = url;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BrowserHistory
{
  Node *curr;

public:
  BrowserHistory(string homepage)
  {
    curr = new Node(homepage);
  }

  void visit(string url)
  {
    Node *newUrl = new Node(url);
    Node *toClear = curr->right;

    curr->right = newUrl;
    newUrl->left = curr;
    curr = newUrl;

    while (toClear != nullptr)
    {
      Node *toDelete = toClear;
      toClear = toClear->right;

      delete toDelete;
    }
  }

  string back(int steps)
  {
    while (steps > 0 && curr->left != nullptr)
    {
      curr = curr->left;
      steps--;
    }

    return curr->url;
  }

  string forward(int steps)
  {
    while (steps > 0 && curr->right != nullptr)
    {
      curr = curr->right;
      steps--;
    }

    return curr->url;
  }
};

void solution()
{
  BrowserHistory browserHistory = BrowserHistory("leetcode.com");
  browserHistory.visit("google.com");
  browserHistory.visit("facebook.com");
  browserHistory.visit("youtube.com");
  cout << browserHistory.back(1) << endl; // facebook
  cout << browserHistory.back(1) << endl; // google
  cout << browserHistory.forward(1) << endl; // facebook
  browserHistory.visit("linkedin.com");
  cout << browserHistory.forward(2) << endl; // linedin
  cout << browserHistory.back(2) << endl; // google
  cout << browserHistory.back(7) << endl; // leetcode
}

int main()
{
  solution();

  return 0;
}
