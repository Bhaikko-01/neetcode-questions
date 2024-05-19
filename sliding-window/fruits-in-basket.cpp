/**
 * 1. Brute Force - O(n^2)
 *      Maintain basket1 and basket2
 *      Check how far we can go with basket1 and basket2
 * 2. Sliding Window - O(n)
 *      Maintain basket1, basket2, basket1LastIndex, basket2LastIndex
 *      Maintain window containing elements for valid bucket1 and bucket2
 *        Update lastIndexes accordingly when iteratin
 *        If invalid config encountered,
 *          if basket1LastIndex > basket2LastIndex
 *            this means basket1 occurs after basket2, should empty basket2
 *            as config before basket2Index is whole invalid now
 *          else
 *            this means basket1 occurs before basket2, should empty basket1 and transfer basket2 to basket1
 *        ans = max(ans, r - l + 1)
 *      Sliding window works because we will empty basket1 when l++ but wont empty basket2
 *        as that will give invalid config already so only option is to empty basket1
*/

#include <bits/stdc++.h>

using namespace std;

int totalFruitBrute(vector<int>& fruits)
{
  int n = fruits.size();
  int ans = 0;

  for (int i = 0; i < n; i++) {
    int basket1 = -1,
        basket2 = -1;

    int currCount = 0;

    for (int j = i; j < n; j++) {
      if (basket1 != fruits[j] && basket2 != fruits[j]) {
        if (basket1 == -1) {
          basket1 = fruits[j];
        } else if (basket2 == -1) {
          basket2 = fruits[j];
        } else {
          break;
        }
      }

      currCount++;
    }

    ans = max(ans, currCount);
  }

  return ans;
}

int totalFruit(vector<int>& fruits)
{
  int n = fruits.size();
  int ans = 0;

  int l = 0,
      r = 0;

  int basket1 = -1,
      basket2 = -1;
  int lastBasket1Index = -1;
  int lastBasket2Index = -1;

  while (r < n) {
    int currFruit = fruits[r];

    if (basket1 == currFruit) {
      lastBasket1Index = r;
    } else if (basket2 == currFruit) {
      lastBasket2Index = r;
    } else if (basket1 == -1) {
      basket1 = currFruit;
      lastBasket1Index = r;
    } else if (basket2 == -1) {
      basket2 = currFruit;
      lastBasket2Index = r;
    } else if (basket1 != currFruit && basket2 != currFruit) {
      if (lastBasket1Index > lastBasket2Index) {
        // Free basket 2 only
        basket2 = -1;
        l = lastBasket2Index + 1;
      } else {
        // Free basket1 and transfer basket2 to basket1
        basket1 = basket2;
        basket2 = -1;

        l = lastBasket1Index + 1;
        lastBasket1Index = lastBasket2Index;
      }
      continue;
    }

    ans = max(ans, r - l + 1);

    r++;
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << totalFruit(nums) << endl;
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
