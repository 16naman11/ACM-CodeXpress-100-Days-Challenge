/*You are given an array nums of n elements. Construct a binary search tree from the given array (just like previous days questions).then print the length of longest zig-zag path

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
Print the longest ZigZag path contained in that tree.*/


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

// A function to find the height of a binary tree
// It takes the root node as a parameter and returns an integer representing the height
// The height of an empty tree is -1
int height(Node* root) {
  // If the tree is empty, return -1
  if (root == NULL) {
    return 0;
  }

  // Find the height of the left and right subtrees recursively
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  // Return the maximum of the left and right heights plus one
  return max(leftHeight, rightHeight) + 1;
}

class Solution {
    int count=0;
    void finder(Node* node,bool isPrevleft,int steps){
        if(!node)return;
        count=max(count,steps);
        if(isPrevleft){
            finder(node->right,false,steps+1);
            finder(node->left,true,1);
        }else{
            finder(node->left,true,steps+1);
            finder(node->right,false,1);
        }
    }
public:
    int longestZigZag(Node* root) {
        count=0;
        finder(root,true,0);
        finder(root,false,0);
        return count;
    }
};

// A main function to test the code
int main() {

  int t;
  cin>>t;
  vector<int> ans;
  Solution s=Solution();
  while(t--){

  Node* root = NULL;
  int n;
  cin>>n;
  vector<int> aux(n);
  for(int i=0;i<n;i++){
    cin>>aux[i];
  }
  for (int i = 0; i < n; i++) {
    root = insert(root, aux[i]);
  }
  ans.push_back(s.longestZigZag(root));
  }
  for(auto it:ans){
    cout<<it<<endl;
  }
  return 0;
}