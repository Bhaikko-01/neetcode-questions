#include <bits/stdc++.h>

using namespace std;

class SeatManager {
private:
  priority_queue<int, vector<int>, greater<int>> minSeats;

public:
    SeatManager(int n) {
      for (int i = 1; i <= n; i++) {
        minSeats.push(i);
      }
    }

    int reserve() {
      int currSeat = minSeats.top();

      minSeats.pop();

      return currSeat;
    }

    void unreserve(int seatNumber) {
      minSeats.push(seatNumber);
    }
};

void solution()
{
  SeatManager* seatManager = new SeatManager(5);

  cout << seatManager->reserve() << endl; // 1
  cout << seatManager->reserve() << endl; // 2
  seatManager->unreserve(2);
  cout << seatManager->reserve() << endl; // 2
  cout << seatManager->reserve() << endl; // 3
  cout << seatManager->reserve() << endl; // 4
  cout << seatManager->reserve() << endl; // 5
  seatManager->unreserve(5);
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
