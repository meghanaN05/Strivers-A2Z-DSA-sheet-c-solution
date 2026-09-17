#include <bits/stdc++.h>
using namespace std;
/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution
{
public:
  bool isSumProperty(Node *root)
  {
    if (!root)
      return true;
    if (!root->left && !root->right)
      return true;
    int l = root->left ? root->left->data : 0;
    int r = root->right ? root->right->data : 0;
    return (root->data == l + r) && isSumProperty(root->left) && isSumProperty(root->right);
  }
};