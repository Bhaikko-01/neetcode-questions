/**
 * 1. Binary Search
 *    Create hash of vectors containing value and timestamp
 *      each value of hash will be a sorted vector as per question
 *      Binary search of exact timestamp
 *      If no timestamp found, r index will point to value just less than target
 *        return this timestamp value
 *      Else
 *        return exact match value
*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
  string key;
  string value;
  int timestamp;
};

class TimeMap {
private:
  unordered_map<string, vector<Node>> store;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
      store[key].push_back({ key, value, timestamp });
    }

    string get(string key, int timestamp)
    {
      if (store.find(key) == store.end()) {
        return "";
      }

      vector<Node> values = store[key];

      int n = values.size();
      int l = 0, r = n - 1;

      while (l <= r) {
        int mid = (l + r) / 2;

        if (values[mid].timestamp == timestamp) {
          return values[mid].value;
        } else {
          if (timestamp > values[mid].timestamp) {
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
      }

      if (r < 0) {
        return "";
      }

      // ! r here represents the element that is JUST LESS THAN searched element
      // ! this is because we choose l and r not exactly as mid but +1 or -1 or it
      return values[r].value;
    }
};

void solution()
{
  TimeMap timeMap;
  timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
  cout << timeMap.get("foo", 1) << endl;         // return "bar"
  cout << timeMap.get("foo", 3) << endl;         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
  timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
  cout << timeMap.get("foo", 4) << endl;         // return "bar2"
  cout << timeMap.get("foo", 5) << endl;
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
