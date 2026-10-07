#include <bits/stdc++.h>
using namespace std;
/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
// brute force approach
class Solution
{
public:
  bool isBST(Node *root, long long low, long long high)
  {
    if (root == NULL)
      return true;
    if (root->data <= low || root->data >= high)
      return false;
    return isBST(root->left, low, root->data) && isBST(root->right, root->data, high);
  }
  int countnodes(Node *root)
  {
    if (root == NULL)
      return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
  }
  int largestBst(Node *root)
  {
    // code here
    if (root == NULL)
      return 0;
    if (isBST(root, LLONG_MIN, LLONG_MAX))
    {
      return countnodes(root);
    }
    return max(largestBst(root->left), largestBst(root->right));
  }
};
// opmtimal solution
// tc: O(n) sc: O(1)
struct NodeInfo
{
  int size;
  int minVal;
  int maxVal;
};
class Solution
{
private:
  NodeInfo solve(Node *root)
  {
    if (root == nullptr)
    {
      return {0, INT_MAX, INT_MIN};
    }
    NodeInfo left = solve(root->left);
    NodeInfo right = solve(root->right);

    if (left.maxVal < root->data && root->data < right.minVal)
    {
      return {
          1 + left.size + right.size,
          min(root->data, left.minVal),
          max(root->data, right.maxVal)};
    }

    // If not a valid BST, return an invalid range [INT_MIN, INT_MAX]
    // This ensures parent nodes will fail the (left.maxVal < root->data < right.minVal) check
    return {
        max(left.size, right.size),
        INT_MIN,
        INT_MAX};
  }

public:
  int largestBst(Node *root)
  {
    return solve(root).size;
  }
};
