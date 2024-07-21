#include <bits/stdc++.h>

using namespace std;

string findDifferentBinaryString(vector<string>& nums, int currIndex, string& currString)
{
  int n = nums.size();

  if (currIndex == n) {
    for (string num: nums) {
      if (currString == num) {
        return "";
      }
    }

    return currString;
  }

  currString[currIndex] = '0';

  string stringWithZero = findDifferentBinaryString(nums, currIndex + 1, currString);
  if (stringWithZero != "") {
    return stringWithZero;
  }

  currString[currIndex] = '1';
  return findDifferentBinaryString(nums, currIndex + 1, currString);
}

string findDifferentBinaryString(vector<string>& nums)
{
  int n = nums.size();
  string currString = string(n, '-');

  return findDifferentBinaryString(nums, 0, currString);
}

void solution()
{
  int n;
  cin >> n;

  vector<string> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << findDifferentBinaryString(nums) << endl;
}

int main()
{
  solution();

  return 0;
}
