/**
 * 1. Brute Force - O(q*m*n)
 *      For every query, calculate sum from [row1, row2] amd [col1, col2]
 * 2. Prefix Sum - O(q*m)
 *      Maintain prefixSum at each point row wise
 *      For a query,
 *        get prefixSum based on col1 and col2 for every row
 *        sum all prefixSum for each row
 *          sum += (prefixSum[row][col1 - 1] - prefixSum[row][col2 - 1])
 */

#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
private:
  vector<vector<int>> matrix;
  vector<vector<int>> prefixSumByRow;

private:
  void populatePrefixSum() {
    int m = this->matrix.size();
    int n = this->matrix[0].size();

    this->prefixSumByRow = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      int currSum = 0;

      for (int j = 0; j < n; j++) {
        currSum += this->matrix[i][j];

        this->prefixSumByRow[i][j] = currSum;
      }
    }
  }

public:
  NumMatrix(vector<vector<int>>& matrix) {
    this->matrix = matrix;

    this->populatePrefixSum();
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;

    for (int i = row1; i <= row2; i++) {
      int col1Sum = col1 == 0 ? 0 : this->prefixSumByRow[i][col1 - 1];
      int col2Sum = this->prefixSumByRow[i][col2];

      sum += (col2Sum - col1Sum);
    }

    return sum;
  }
};

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  NumMatrix* obj = new NumMatrix(matrix);
  cout << obj->sumRegion(2, 1, 4, 3) << endl;
  cout << obj->sumRegion(1, 1, 2, 2) << endl;
  cout << obj->sumRegion(1, 2, 2, 4) << endl;
}

int main()
{
  solution();

  return 0;
}

/**
5 5
3 0 1 4 2
5 6 3 2 1
1 2 0 1 5
4 1 0 1 7
1 0 3 0 5
 */
