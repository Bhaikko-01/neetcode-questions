/**
 * 1. Heap - O(nlogk)
 *      Maintain array of pairs of nums1 and nums2
 *      Sort array of pair in descending order by nums2 value
 *        This is done as we will calculate equation for every minValue considered from nums2
 *      For each pair,
 *        we add pair.nums1 to sum and push it to heap
 *        If currLen is k, we can calculate ans
 *          We pick pair.nums2 since it will be minTillNow
 *          Since this is picked, we have to pick pair.num1
 *            And pick k-1 elements till now so we maintain sum of max k-1 elements
 *          After current iteration, we pop out min element from minHeap and remove it from sum
 *      maxAns till now is ans
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;
typedef long long ll;

struct MinHeapCompartor {
  bool operator()(int a, int b) {
    return a > b;
  }
};

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
{
  int n = nums1.size();

  vector<pp> pairs(n);

  for (int i = 0; i < n; i++) {
    pairs[i].first = nums1[i];
    pairs[i].second = nums2[i];
  }

  sort(pairs.begin(), pairs.end(), [](pp a, pp b) -> bool {
    return a.second > b.second;
  });

  priority_queue<int, vector<int>, MinHeapCompartor> minElementsHeap;

  int currLen = 0;
  ll sum = 0;
  ll ans = 0;

  for (pp pair: pairs) {
    currLen++;

    sum += pair.first;
    minElementsHeap.push(pair.first);

    if (currLen >= k) {
      ll possibleAns = sum * (ll)pair.second;

      ans = max(possibleAns, ans);

      int minEl = minElementsHeap.top();
      sum -= minEl;
      minElementsHeap.pop();
    }
  }

  return ans;
}

void solution()
{
  int n, k;
  cin >> n >> k;

  vector<int> nums1(n);
  for (int i = 0; i < n; i++) {
    cin >> nums1[i];
  }

  vector<int> nums2(n);
  for (int i = 0; i < n; i++) {
    cin >> nums2[i];
  }

  cout << maxScore(nums1, nums2, k) << endl;
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
