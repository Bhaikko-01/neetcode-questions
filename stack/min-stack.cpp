/**
 * 1. Maintain one stack and search sequentially - O(n) - [T]
 *    For push, pop, top - use one stack
 *    For finding min
 *      pop whole stack, find min and push all elements back
 * 2. Maintain min element for every element in stack - O(1) - [T + S]
 *    For every push in mainStack, push minElement till now to minStack as well
 *      minStack.push(min(val, minStack.top()))
 *    For pop, pop from mainStack and minStack both
 *    For minVal, minStack.top()
 *    For mainStack, mainStack.top()
 * 3. Creating stack from scratch - O(1)
 *    Using Node to create stack
 *    In this, curr Min element will have reference to next minimum element upon every push
 *    Maintain head and minNode pointers and update accordingly
*/

#include <bits/stdc++.h>

using namespace std;

// ! 2.
class MinStack {
private:
  stack<int> auxStack;
  stack <int> mainStack;
public:
  MinStack() {}

  void push(int val) {
    mainStack.push(val);

    int minStackVal = val;
    if (!auxStack.empty()) {
      minStackVal = min(auxStack.top(), val);
    }

    auxStack.push(minStackVal);
  }

  void pop() {
    auxStack.pop();
    mainStack.pop();
  }

  int top() {
    return mainStack.top();
  }

  int getMin() {
    return auxStack.top();
  }
};

void solution()
{
  MinStack* obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);

  cout << obj->getMin() << endl;
  obj->pop();
  cout << obj->top() << endl;

  cout << obj->getMin() << endl;
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
