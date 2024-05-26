  void moveNodeToCorrectPosition(Node* currNode)
  {
    // If there is no left, currNode is head -> do nothing
    while (currNode->left && currNode->left->counter <= currNode->counter) {
      Node* leftNode = currNode->left;
      Node* rightNode = currNode->right;

      Node* leftOfLeft = leftNode->left;

      if (!rightNode) {
        // Current Node is tail

        if (!leftOfLeft) {
          // List has two elements
          // leftNode is head
          leftNode->left = currNode;
          leftNode->right = nullptr;
          tail = leftNode;

          head = currNode;
          currNode->right = leftNode;
          currNode->left = nullptr;
        } else {
          // List has many elements
          leftOfLeft->right = currNode;
          currNode->left = leftOfLeft;

          currNode->right = leftNode;
          leftNode->left = currNode;
          leftNode->right = nullptr;

          tail = leftNode;
        }
      } else if (!leftOfLeft) {
        // Current Node left is head
        leftNode->right = rightNode;
        rightNode->left = leftNode;

        currNode->right = leftNode;
        leftNode->left = currNode;

        currNode->left = nullptr;

        head = currNode;
      } else {
        // Current Node is somewhere middle
        leftOfLeft->right = currNode;
        currNode->left = leftOfLeft;

        currNode->right = leftNode;
        leftNode->left = currNode;

        leftNode->right = rightNode;
        rightNode->left = leftNode;
      }
    }
  }
