#include <bits/stdc++.h>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const {}

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const {}

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger>& getList() const {}
};

struct NestedIntegerStackFrame {
  int returnIndex;
  vector<NestedInteger> nestedIntegerList;

public:
  NestedIntegerStackFrame(int returnIndex, vector<NestedInteger> nestedIntegerList):
    returnIndex(returnIndex), nestedIntegerList(nestedIntegerList) {}
};

class NestedIterator {
private:
  stack<NestedIntegerStackFrame> stackFrames;

  int currIndex;

private:
  void moveCurrIndexToValidPosition()
  {
    while (true) {
      bool validPosFound = false;

      if (stackFrames.empty()) {
        break;
      }

      while (true) {
        if (stackFrames.empty()) {
          break;
        }

        NestedIntegerStackFrame& stackFrame = stackFrames.top();
        vector<NestedInteger>& topNestedIntegerList = stackFrame.nestedIntegerList;

        if (currIndex >= topNestedIntegerList.size()) {
          stackFrames.pop();
          currIndex = stackFrame.returnIndex;
        } else {
          break;
        }
      }

      if (stackFrames.empty()) {
        break;
      }

      while (true) {
        NestedIntegerStackFrame& stackFrame = stackFrames.top();
        vector<NestedInteger>& topNestedIntegerList = stackFrame.nestedIntegerList;

        NestedInteger nestedInteger = topNestedIntegerList[currIndex];

        if (nestedInteger.isInteger()) {
          validPosFound = true;
          break;
        } else {
          if (topNestedIntegerList[currIndex].getList().size() == 0) {
            currIndex++;
            break;
          } else {
            NestedIntegerStackFrame stackFrame(currIndex + 1, nestedInteger.getList());

            stackFrames.push(stackFrame);
            currIndex = 0;
          }
        }
      }


      if (validPosFound) {
        break;
      }
    }
  }

public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    currIndex = 0;

    NestedIntegerStackFrame stackFrame(0, nestedList);

    stackFrames.push(stackFrame);
  }

  int next() {
    NestedIntegerStackFrame& stackFrame = stackFrames.top();
    vector<NestedInteger>& topNestedIntegerList = stackFrame.nestedIntegerList;

    NestedInteger nestedInteger = topNestedIntegerList[currIndex];

    int intToRet = nestedInteger.getInteger();

    currIndex++;

    return intToRet;
  }

  bool hasNext() {
    moveCurrIndexToValidPosition();

    return !stackFrames.empty();
  }
};

void solution()
{

}

int main()
{
  solution();

  return 0;
}
