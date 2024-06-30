#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
  vector<int> ans;
  stack<int> pending;

  for (int incomingAsteroid : asteroids) {
    bool incomingDestroyed = false;

    while (!pending.empty()) {
      int currAsteroid = pending.top();

      if (currAsteroid > 0 && incomingAsteroid < 0) {
        if (currAsteroid == -incomingAsteroid) {
          incomingDestroyed = true;
          pending.pop();
          break;
        }

        if (currAsteroid > -incomingAsteroid) {
          incomingDestroyed = true;
          break;
        }

        if (currAsteroid < -incomingAsteroid) {
          pending.pop();
        }
      } else {
        break;
      }
    }

    if (!incomingDestroyed) {
      pending.push(incomingAsteroid);
    }
  }

  while (!pending.empty()) {
    ans.push_back(pending.top());

    pending.pop();
  }

  reverse(ans.begin(), ans.end());

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> asteroids(n);
  for (int i = 0; i < n; i++) {
    cin >> asteroids[i];
  }

  vector<int> ans = asteroidCollision(asteroids);

  for (int x : ans) {
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
