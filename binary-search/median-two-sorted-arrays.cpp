/**
 * 1. Brute force - O(m + n)
 *    Merge both array and find median element
 * 2. Binary search on Partitions - o(logn)
 *    Find partition in both arrays such that
 *      Elements in left partition are all less than elements in right partition
 *      Number of Elements in left partition are equal to number of elements in right partition
 *    Find cuts for partition
 *      cut1 = (l + r) / 2
 *      cut2 = (m + n) / 2 - cut1
 *      Using cut1 and cut2, comparison pointers are derived, l1, l2, r1, r2
 *        eg. l1 = nums1[cut1 - 1]
 *    Assume INT_MIN and INT_MAX for out of bounds value for l1, l2, r1, r2
 *    Validate Parition by comparing l1 <= r2 and l2 <= r1
 *      This is because we need to check if all elements in left part are less than right part
 *      No need to compare l1 <= r1 and l2 <= r2 since they belong to same array and are sorted
 *    If correct partition found,
 *      Median is in one of these four elements because we know they lie in middle but dont know the actual order
 *      If m + n is even -> (max(l1, l2) + min(r1, r2)) / 2
 *      Else -> min(r1, r2)
 *    Else check which parition is wrong
 *      If l1 > r2 -> r = cut1 - 1 // Because we need to move r1 in right parition
 *      Else if l2 > r1 -> l = cut1 + 1 // Because we need to move r1 in left partition
*/
#include <bits/stdc++.h>

using namespace std;

double medianOfTwoSorted(vector<int>& nums1, vector<int>& nums2, int l, int r)
{
  int cut1 = (l + r) / 2;
  int cut2 = (nums1.size() + nums2.size()) / 2 - cut1;

  // ! Assuming out of Bound values to be -INF and INF for comparison
  int l1 = cut1 <= 0 ? INT_MIN : nums1[cut1 - 1];
  int l2 = cut2 <= 0 ? INT_MIN : nums2[cut2 - 1];

  int r1 = cut1 == nums1.size() ? INT_MAX : nums1[cut1];
  int r2 = cut2 == nums2.size() ? INT_MAX : nums2[cut2];

  if (l1 <= r2 && l2 <= r1) {
    if ((nums1.size() + nums2.size()) & 1) {
      return min(r1, r2);
    } else {
      return (
          max(l1, l2) + min(r1, r2)
      ) / 2.0f;
    }
  }

  if (l1 > r2) {
    return medianOfTwoSorted(nums1, nums2, l, cut1 - 1);
  } else {
    return medianOfTwoSorted(nums1, nums2, cut1 + 1, r);
  }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
  return (nums1.size() <= nums2.size()) ?
      medianOfTwoSorted(nums1, nums2, 0, nums1.size()) :
      medianOfTwoSorted(nums2, nums1, 0, nums2.size());

}

void solution()
{
  int m, n;
  cin >> m >> n;

  vector<int> nums1(m), nums2(n);
  for (int i = 0; i < m; i++) {
    cin >> nums1[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> nums2[i];
  }

  cout << findMedianSortedArrays(nums1, nums2) << endl;
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
