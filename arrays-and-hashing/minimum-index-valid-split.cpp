#include <bits/stdc++.h>

using namespace std;

using pp = pair<int, int>;

pp getDominantElement(vector<int>& nums)
{
  int n = nums.size();

  unordered_map<int, int> occurence;
  for (int num: nums) {
    occurence[num]++;
  }

  int dominantEl = INT_MIN;
  int dominantElOcc = INT_MIN;

  for (auto it = occurence.begin(); it != occurence.end(); it++) {
    if (it->second > dominantElOcc) {
      dominantElOcc = it->second;
      dominantEl = it->first;
    }
  }

  return {dominantEl, dominantElOcc};
}

int minimumIndex(vector<int>& nums)
{
  int n = nums.size();

  pp dominantElPp = getDominantElement(nums);

  int dominantEl = dominantElPp.first;
  int rightOcc = dominantElPp.second;

  int leftOcc = 0;

  for (int i = 0; i < n - 1; i++) {
    if (nums[i] == dominantEl) {
      rightOcc--;
      leftOcc++;
    }

    int leftSize = i + 1;
    int rightSize = n - i - 1;

    if (leftOcc > leftSize / 2 && rightOcc > rightSize / 2) {
      return i;
    }
  }

  return -1;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << minimumIndex(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
