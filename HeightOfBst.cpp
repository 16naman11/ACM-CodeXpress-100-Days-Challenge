/*You are given an unsorted array nums of n elements, where each element is an integer. Your task is to create a binary search tree from the array and print the height of the tree. A binary search tree is a binary tree where the value of each node is greater than or equal to the values of its left subtree and less than the values of its right subtree. The height of a binary tree is the number of edges on the longest path from the root node to a leaf node.*/

#include <iostream>

#include <stack>

using namespace std;

struct Node {

  int data;

  Node* left;

  Node* right;

};

Node* createNode(int data) {

  Node* newNode = new Node();

  if (!newNode) {

    cout << "Memory error\n";

    return NULL;

  }

  newNode->data = data;

  newNode->left = newNode->right = NULL;

  return newNode;

}

Node* insertNode(Node* root, int data) {

  if (root == NULL) {

    root = createNode(data);

    return root;

  }

  Node* curr = root;

  while (true) {

    if (data < curr->data) {

      if (curr->left == NULL) {

        curr->left = createNode(data);

        break;

      } else {

        curr = curr->left;

      }

    } else if (data > curr->data) {

      if (curr->right == NULL) {

        curr->right = createNode(data);

        break;

      } else {

        curr = curr->right;

      }

    } else {

      break;

    }

  }

  return root;

}

int getHeight(Node* root) {

    if (root == NULL) {

        return 0;

    }

    stack<Node*> s;

    s.push(root);

    int maxHeight = 0;  // Initialize maxHeight to 0

    while (!s.empty()) {

        Node* curr = s.top();

        s.pop();

        int currHeight = 1 + max(getHeight(curr->left), getHeight(curr->right));  // Calculate height from children

        maxHeight = max(maxHeight, currHeight);  // Update maxHeight with calculated height

    }

    return maxHeight;

}

int main() {

  int T;

  cin >> T;

  while (T--) {

    int n;

    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {

      int num;

      cin >> num;

      root = insertNode(root, num);

    }

    int height = getHeight(root);

    cout << height << endl;

  }

  return 0;

}