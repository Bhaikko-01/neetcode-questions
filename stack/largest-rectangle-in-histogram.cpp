/**
 * 1. Brute Force - O(n^2) [T]
 *    Try expanding heights[i] in both directions such that we go till we get heights greater than current height
 *      leftReach and rightReach index should NOT be the one of less height than current
 *        but just before that since that will determine the width
 *      width = rightReach - leftReach + 1
 *      area = heights[i] * width  // No need to consider heights of others as current height will be
 *                                     since we searched for heights less than current and skipped the ones greater
 * 2. Store nextLessElementIndex in both directions
 *    We do this as just before this minHeight, we will have the max height to which we can span the current element
 *    Fill leftReachIndexes and rightReachIndexes using stack
 *      fill indexes just before and after rather than actual min index
 *      for no index from filling, assign 0 and n - 1 respectively
 *        this means, current rectangle can span till last as no max was found
 *    Calculate area for each index and find maxArea
 *       width = rightReactIndexes[i] - leftReachIndexes[i] + 1
 *      area = heights[i] * width
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1.
int largestRectangleAreaBrute(vector<int>& heights)
{
  int n = heights.size();
  int maxArea = 0;

  for (int i = 0; i < n; i++) {
    int leftReach = i;

    while (leftReach - 1 >= 0 && heights[leftReach - 1] >= heights[i]) {
      leftReach--;
    }

    int rightReach = i;
    while (rightReach + 1 < n && heights[rightReach + 1] >= heights[i]) {
      rightReach++;
    }

    int area = heights[i] * (rightReach - leftReach + 1);

    maxArea = max(maxArea, area);
  }

  return maxArea;
}

// ! 2.
int largestRectangleArea(vector<int>& heights)
{
  int n = heights.size();
  int maxArea = 0;

  vector<int> leftReactIndexes(n), rightReachIndexes(n);
  stack<int> minLeftReactIndexes, minRightReachIndexes;

  for (int i = 0; i < n; i++) {
    if (!minLeftReactIndexes.empty() && heights[minLeftReactIndexes.top()] < heights[i]) {
      leftReactIndexes[i] = minLeftReactIndexes.top() + 1;
    } else {
      while (!minLeftReactIndexes.empty() && heights[minLeftReactIndexes.top()] >= heights[i]) {
        minLeftReactIndexes.pop();
      }

      leftReactIndexes[i] = minLeftReactIndexes.empty() ? 0 : minLeftReactIndexes.top() + 1;
    }

    minLeftReactIndexes.push(i);
  }

  for (int i = n - 1; i >= 0; i--) {
    if (!minRightReachIndexes.empty() && heights[minRightReachIndexes.top()] < heights[i]) {
      rightReachIndexes[i] = minRightReachIndexes.top() - 1;
    } else {
      while (!minRightReachIndexes.empty() && heights[minRightReachIndexes.top()] >= heights[i]) {
        minRightReachIndexes.pop();
      }

      rightReachIndexes[i] = minRightReachIndexes.empty() ? n - 1 : minRightReachIndexes.top() - 1;
    }

    minRightReachIndexes.push(i);
  }

  for (int i = 0; i < n; i++) {
    int width = rightReachIndexes[i] - leftReactIndexes[i] + 1;
    maxArea = max(maxArea, width * heights[i]);
  }

  return maxArea;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> heights(n);
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  cout << largestRectangleArea(heights) << endl;
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
