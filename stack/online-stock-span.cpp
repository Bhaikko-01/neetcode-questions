#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

class StockSpanner {
private:
  void insertAtCorrectPlace(int val)
  {
    int daysCount = 1;
    while (!prevStocks.empty()) {
      pp topValue = prevStocks.top();

      if (topValue.first <= val) {
        daysCount += topValue.second;
        prevStocks.pop();
      } else {
        break;
      }
    }

    prevStocks.push({ val, daysCount });
  }

public:
  stack<pp> prevStocks;

  StockSpanner() {
  }

  int next(int price) {
    insertAtCorrectPlace(price);

    return prevStocks.top().second;
  }
};

void solution()
{
  StockSpanner stockSpanner = StockSpanner();
  cout << stockSpanner.next(100) << endl; // return 1
  cout << stockSpanner.next(80) << endl;  // return 1
  cout << stockSpanner.next(60) << endl;  // return 1
  cout << stockSpanner.next(70) << endl;  // return 2
  cout << stockSpanner.next(60) << endl;  // return 1
  cout << stockSpanner.next(75) << endl;  // return 4
  cout << stockSpanner.next(85) << endl;  // return 6
}

int main()
{
  // int n;
  // cin >> n;

  // for (int i = 1; i <= n; i++) {
    solution();
  // }

  return 0;
}
