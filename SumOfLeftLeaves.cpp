/*You are given an array nums of n elements. Construct a binary search tree from the given array (just like previous days questions).Print the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.*/

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

// A function to find the sum of all left leaf nodes in a binary tree
int sumLeftLeaves(Node* root) {
  if (!root) {
    return 0;
  }

  // If the left child is a leaf, add its value to the sum
  int sum = 0;
  if (root->left && !root->left->left && !root->left->right) {
    sum += root->left->data;
  }

  // Recursively calculate the sum for the left and right subtrees
  sum += sumLeftLeaves(root->left);
  sum += sumLeftLeaves(root->right);

  return sum;
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
    ans.push_back(sumLeftLeaves(root));
  }
  for (auto it : ans) {
    cout << it << endl;
  }
  return 0;
}
