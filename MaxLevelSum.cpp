/*You are given an array nums of n elements. Construct a binary search tree from the given array (just like previous days questions) then print the level with maximum sum.

The level of its root is 1, the level of its children is 2, and so on.

Print the smallest level x such that the sum of all the values of nodes at level x is maximal.*/

#include <bits/stdc++.h>
using namespace std;

// A node structure for the binary search tree
struct Node {
  int data; // The value stored in the node
  Node* left; // The pointer to the left child
  Node* right; // The pointer to the right child

  // A constructor to create a new node with a given value
  Node(int value) {
    data = value;
    left = NULL;
    right = NULL;
  }
};

// A function to insert a new value into a binary search tree
// It takes the root node and the value as parameters and returns the updated root node
Node* insert(Node* root, int value) {
  // If the tree is empty, create a new node with the value and return it
  if (root == NULL) {
    return new Node(value);
  }

  // If the value is less than the root node, insert it into the left subtree
  if (value <= root->data) {
    root->left = insert(root->left, value);
  }
  // If the value is greater than the root node, insert it into the right subtree
  else if (value > root->data) {
    root->right = insert(root->right, value);
  }

  // Return the root node (the root of the modified tree)
  return root;
}

// A function to find the level with the maximum sum in a binary tree
int findMaxSumLevel(Node* root) {
  if (!root) {
    return 0;
  }

  queue<Node*> q;
  q.push(root);
  int maxLevel = 0;
  int maxSum = INT_MIN;
  int level = 0;

  while (!q.empty()) {
    level++;
    int size = q.size();
    int currentSum = 0;

    for (int i = 0; i < size; i++) {
      Node* current = q.front();
      q.pop();
      currentSum += current->data;

      if (current->left) {
        q.push(current->left);
      }

      if (current->right) {
        q.push(current->right);
      }
    }

    if (currentSum > maxSum) {
      maxSum = currentSum;
      maxLevel = level;
    }
  }

  return maxLevel;
}

// A main function to test the code
int main() {
  int t;
  cin >> t;
  vector<int> ans;
  while (t--) {
    Node* root = NULL;
    int n;
    cin >> n;
    vector<int> aux(n);
    for (int i = 0; i < n; i++) {
      cin >> aux[i];
    }
    for (int i = 0; i < n; i++) {
      root = insert(root, aux[i]);
    }
    ans.push_back(findMaxSumLevel(root));
  }
  for (auto it : ans) {
    cout << it << endl;
  }
  return 0;
}
