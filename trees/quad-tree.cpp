#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node()
  {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

bool allValuesSame(vector<vector<int>>& grid, int top, int bottom, int left, int right, int val)
{
  for (int i = top; i <= bottom; i++) {
    for (int j = left; j <= right; j++) {
      if (grid[i][j] != val) {
        return false;
      }
    }
  }

  return true;
}

Node* construct(vector<vector<int>>& grid, int top, int bottom, int left, int right)
{
  if (top > bottom || left > right) {
    return nullptr;
  }

  if (top == bottom && left == right) {
    return new Node(grid[top][left], true);
  }

  bool allZeroes = allValuesSame(grid, top, bottom, left, right, 0);
  bool allOnes = allValuesSame(grid, top, bottom, left, right, 1);

  if (allZeroes) {
    return new Node(0, true);
  }

  if (allOnes) {
    return new Node(1, true);
  }

  Node* newNode = new Node(0, false);
  int verticalMid = (top + bottom) / 2;
  int horizontalMid = (left + right) / 2;

  newNode->topLeft = construct(grid, top, verticalMid, left, horizontalMid);
  newNode->topRight = construct(grid, top, verticalMid, horizontalMid + 1, right);
  newNode->bottomLeft = construct(grid, verticalMid + 1, bottom, left, horizontalMid);
  newNode->bottomRight = construct(grid, verticalMid + 1, bottom, horizontalMid + 1, right);

  return newNode;
}

Node* construct(vector<vector<int>>& grid)
{
  int n = grid.size();

  return construct(grid, 0, n - 1, 0, n - 1);
}

void solution()
{
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  Node* ans = construct(grid);
}

int main()
{
  solution();

  return 0;
}
