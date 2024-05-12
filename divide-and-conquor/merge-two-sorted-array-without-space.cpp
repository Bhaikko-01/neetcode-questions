/**
 *    Create final arrays such that all elements in arr1 are less than arr2
 * 1. Insertion sort Without extra space - O(n*m)
 *      Need to update arrays like
 *        First array last element is smaller than second array first element
 *      Check elements of arr1 and arr2.
 *      if arr1[i] > arr2[0]
 *        this greater element should exist in arr2
 *        swap with 0th index and move the swapped element in arr2 to correct position
 *          using insertion sort technique
*/

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int n, vector<int>& nums2, int m)
{
  if (n == 0 || m == 0) {
    return;
  }

  for (int i = 0; i < n; i++) {
    if (nums1[i] > nums2[0]) {
      swap(nums1[i], nums2[0]);

      for (int j = 0; j + 1 < m; j++) {
        if (nums2[j] > nums2[j + 1]) {
          swap(nums2[j], nums2[j + 1]);
        } else {
          break;
        }
      }
    }
  }
}

void solution()
{
  int n, m;
  cin >> n >> m;

  vector<int> nums1(n), nums2(m);

  for (int i = 0; i < n; i++) {
    cin >> nums1[i];
  }

  for (int j = 0; j < m; j++) {
    cin >> nums2[j];
  }

  merge(nums1, n, nums2, m);

  for (int x: nums1) {
    cout << x << " ";
  }

  for (int x: nums2) {
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
