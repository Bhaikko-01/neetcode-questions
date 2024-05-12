/**
 * 1. Brute Force - O(k(n-k)) ~ O(n^2)
 *    Iterate through every subarray of array
 *    Find max repeatedly and return
 * 2. Using Heap for window - O(nlogn)
 *    Push elements to max heap from window and get top element
 *    Pop from head if exiting element from window is top
 * 3. Using monotonically decreasing dequeue - O(n)
 *    deque allows push and pop from both ends  AND  Values in deque will always be in decreasing order
 *    Elements to left in a window can be ignored since they never will be max. Only consider right elements
 *    Front value in deque will always be max.
 *      Pop values from right till nums[r] > queue.back()
 *      Insert value from right
 *    Max element in that window will be at top.
 *      Push that element to ans
 *      If that element is exiing the window, pop from queue
 *    Above operations should be performed if (r - l + 1 == windowSize)
 * ! Note: In slicing of vector in CPP, end pointer is exclusive
 *  ! Hence the end pointer should point to next element till which we are slicing
*/

#include <bits/stdc++.h>

using namespace std;

// ! 1.
vector<int> maxSlidingWindowBrute(vector<int>& nums, int k)
{
  int n = nums.size();
  vector<int> ans;

  for (int i = 0; i <= n - k; i++) {
    int currMax = INT_MIN;
    // ! Slicing vector in Cpp
    for (int x: vector(nums.begin() + i, nums.begin() + i + k)) {
      currMax = max(currMax, x);
    }
    ans.push_back(currMax);
  }

  return ans;
}

// ! 3.
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
  int n = nums.size();
  vector<int> ans;

  deque<int> maxQueue;

  int l = 0, r = 0;

  while (r < n) {
    int el = nums[r];

    while (!maxQueue.empty() && maxQueue.back() < el) {
      maxQueue.pop_back();
    }

    maxQueue.push_back(el);

    int windowLength = r - l + 1;

    // ! Only processing ans if we have reached window size
    if (windowLength == k) {
      ans.push_back(maxQueue.front());

      if (nums[l] == maxQueue.front()) {
        maxQueue.pop_front();
      }
      l++;
    }

    r++;
  }

  return ans;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> ans = maxSlidingWindow(nums, k);

  for (int x: ans) {
    cout << x << " ";
  }
  cout << endl;
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
