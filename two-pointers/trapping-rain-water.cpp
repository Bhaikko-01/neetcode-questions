/**
 * 1. Brute Force - O(n^2) [T]. Dont really need to code this. My own solution and im proud of it
 *  For every index, calculate left max height and right max height
 *  If no left max or right max found, continue
 *  Else,
 *    Calculate possible water from leftMax to rightMax based on min(leftMax, rightMax)
 *    if (leftMax > rightMax) -> traverse right to left
 *    else traverse left to right
 *      add water till height greater than minHeight found
 *        water += (minHeight - height[i]) * 1
 *      Mark traversed height to not add it again
 * 2. Calculate each Index only - O(n^2) [T]
 *  Calculate maxLeft and maxRight for each index
 *  water += max(0, min(maxLeft, maxRight) - height[i])
 * 3. Memoize maxLeft and maxRight for each index - O(n) [T + S]
 *  Calculate maxLeft and maxRight for each index
 *    maxLeft[i] = max(maxLeft[i - 1], height[i]), maxLeft[0] = height[0]
 *    maxRight[i] = max(maxRight[i + 1], height[i]), maxRight[n - 1] = height[n - 1]
 *  Calculate water
 *    water += max(0, min(maxLeft[i], maxRight[i]) - height[i])
 * 4. Two pointer, bottleneck method, waterPointer - O(n) [T]
 *  Since min(maxLeft, maxRight) is calculated at each point based on bottleneck
 *    If current maxLeft is less than known maxRight then no need to find bigger maxRight
 *    If current maxRight is less than known maxLeft then no need to find bigger maxLeft
 *  waterPointer is where the bottleneck was found. Calculate water at that point only.
 *    Update pointer and maxLeft or maxRight then
 *  if maxLeft < maxRight => water += max(0, maxLeft - height[l]), l++, maxLeft = max(maxLeft, height[i])
 *  else => water += max(0, maxRight - height[r]), r--, maxRight = max(maxRight, height[r])
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1
int calculateWater(vector<int>& height, int l, int r, vector<bool>& traversed)
{
  int water = 0;
  int minHeight = min(height[l], height[r]);

  if (height[l] < height[r]) {
    for (int i = l + 1; i < r; i++) {
      if (height[i] > minHeight) {
        break;
      }

      traversed[i] = true;

      water += minHeight - height[i];
    }
  } else {
    for (int i = r - 1; i > l; i--) {
      if (height[i] > minHeight) {
        break;
      }

      traversed[i] = true;

      water += minHeight - height[i];
    }
  }

  return water;
}

int trapBrute(vector<int>& height)
{
  int n = height.size();
  int waterCount = 0;

  vector<bool> traversed(n, false);

  for (int i = 0; i < n; i++) {
    if (traversed[i]) {
      continue;
    }

    int minHeight = height[i];
    int l = -1, r = -1;

    // find index of maxHeight in left
    for (int j = i - 1; j >= 0; j--) {
      if (height[j] >= minHeight) {
        minHeight = height[j];
        l = j;
      }
    }

    minHeight = height[i];

    // find index of maxHeight in right
    for (int j = i + 1; j < n; j++) {
      if (height[j] >= minHeight) {
        minHeight = height[j];
        r = j;
      }
    }

    if (l == -1 || r == -1) {
      continue;
    }

    // ! 1
    // waterCount += calculateWater(height, l, r, traversed);

    // ! 2
    waterCount += max(0, min(height[l], height[r]) - height[i]);
  }

  return waterCount;
}

// ! 3
int trapMemo(vector<int>& height)
{
  int n = height.size();

  vector<int> maxLefts(n, -1);
  vector<int> maxRights(n, -1);

  maxLefts[0] = height[0];
  for (int i = 1; i < n; i++) {
    maxLefts[i] = max(maxLefts[i - 1], height[i]);
  }

  maxRights[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    maxRights[i] = max(maxRights[i + 1], height[i]);
  }

  int water = 0;

  for (int i = 0; i < n; i++) {
    water += max(0, min(maxLefts[i], maxRights[i]) - height[i]);
  }

  return water;
}

// ! 4
int trap(vector<int>& height)
{
  int n = height.size();

  int l = 0, r = n - 1,
      maxLeft = height[0],
      maxRight = height[n - 1];

  int water = 0;

  while (l < r) {
    if (maxLeft < maxRight) {
      water += max(0, maxLeft - height[l]);
      l++;
      maxLeft = max(maxLeft, height[l]);
    } else {
      water += max(0, maxRight - height[r]);
      r--;
      maxRight = max(maxRight, height[r]);
    }
  }

  return water;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> height(n);
  for (int i = 0; i < n; i++) {
    cin >> height[i];
  }

  cout << trap(height) << endl;
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
