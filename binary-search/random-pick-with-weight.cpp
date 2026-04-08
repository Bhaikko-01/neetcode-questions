#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct RandomPickElement {
  int num;
  int index;
  double prob;
};

class Solution {
private:
  vector<RandomPickElement> nums;

public:
    Solution(vector<int>& w) {
      ll currSum = 0;

      for (int x: w) {
        currSum += x;
      }

      double running = 0;

      for (int i = 0; i < w.size(); i++) {
        running += w[i] / (double)currSum;
        nums.push_back({w[i], i, running});
      }
    }

  int pickIndex() {
    double r = ((double) rand() / (RAND_MAX));

    auto it = lower_bound(
      nums.begin(),
      nums.end(),
      r,
      [](
        const RandomPickElement& first,
        double value
      ) -> bool {

        return first.prob < value;
      }
    );

    return it->index;
  }
};

void solution()
{
  vector<int> nums = { 1, 3 };
  Solution sol(nums);

  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
  cout << sol.pickIndex() << endl;
}

int main()
{
  solution();

  return 0;
}
