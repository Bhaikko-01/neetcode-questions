#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& graph, int r, int c)
{
  int n = graph.size();

  if (r < 0 || r >= n || c < 0 || c >= n || graph[r][c] != 0) {
    return;
  }

  graph[r][c] = -1;

  dfs(graph, r - 1, c);
  dfs(graph, r, c - 1);
  dfs(graph, r + 1, c);
  dfs(graph, r, c + 1);
}

int regionsBySlashes(vector<string>& grid)
{
  int n = grid.size();
  int graphSize = 4 * n;
  vector<vector<int>> graph(graphSize);
  for (int i = 0; i < graphSize; i++) {
    vector<int> row(graphSize, 0);

    graph[i] = row;
  }

  for (int i = 0; i < n; i++) {
    string word = grid[i];

    for (int j = 0; j < word.size(); j++) {
      char c = word[j];

      vector<vector<int>> block(4);

      if (c == ' ') {
        block[0] = { 0, 0, 0, 0};
        block[1] = { 0, 0, 0, 0};
        block[2] = { 0, 0, 0, 0};
        block[3] = { 0, 0, 0, 0};
      } else if (c == '/') {
        block[0] = { 0, 0, 0, 1 };
        block[1] = { 0, 0, 1, 0 };
        block[2] = { 0, 1, 0, 0 };
        block[3] = { 1, 0, 0, 0 };
      } else if (c == '\\') {
        block[0] = { 1, 0, 0, 0 };
        block[1] = { 0, 1, 0, 0 };
        block[2] = { 0, 0, 1, 0 };
        block[3] = { 0, 0, 0, 1 };
      }

      for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
          graph[4 * i + x][4 * j + y] = block[x][y];
        }
      }
    }
  }

  int count = 0;

  // ! Printing New graph
  // int rowCount = 0, colCount = 0;
  // for (auto x: graph) {
  //   for (auto y: x) {
  //     cout << y << " ";
  //     colCount++;
  //     if (colCount % 4 == 0) {
  //       cout << " | ";
  //     }
  //   }
  //   cout << endl;
  //   rowCount++;
  //   if (rowCount % 4 == 0) {
  //     cout << " --------" << endl;
  //   }
  // }

  for (int i = 0; i < graphSize; i++) {
    for (int j = 0; j < graphSize; j++) {
      if (graph[i][j] == 0) {
        dfs(graph, i, j);
        count++;
      }
    }
  }

  return count;
}

void solution()
{
  vector<string> grid = { " /", "/ " };
  // vector<string> grid = { " /", " " };
  // vector<string> grid = { "/\\", "\\/" };

  cout << regionsBySlashes(grid) << endl;
}

int main()
{
  solution();

  return 0;
}
