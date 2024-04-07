/**
 * 1. Brute Force - Find all possible width and get area - O(n^2)
 *  For every possible width, maxArea = max(maxArea, j - i * min(heights[i], heights[j]))
 * 2. Two pointer - Take decision based on current height - O(n)
 *  l and r are updated based on height of current point.
 *  If a[l] < a[r], go right
 *  otherwise go left
*/

#include <bits/stdc++.h>

using namespace std;

// ! 2.
int maxArea(vector<int>& height)
{
  int n = height.size();

  int l = 0,
      r = n - 1,
      ans = 0;

  while (l < r) {
    int width = r - l;
    ans = max(ans, width * min(height[l], height[r]));

    if (height[l] < height[r]) {
      l++;
    } else {
      r--;
    }
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> height(n);
  for (int i = 0; i < n; i++) {
    cin >> height[i];
  }

  cout << maxArea(height) << endl;
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
