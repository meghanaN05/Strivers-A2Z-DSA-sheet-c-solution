#include <bits/stdc++.h>
using namespace std;
/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution
{
public:
  vector<Node *> findPreSuc(Node *root, int key)
  {
    // code here
    Node *pre = NULL;
    Node *suc = NULL;
    while (root != NULL)
    {
      if (root->data == key)
      {
        if (root->left)
        {
          Node *t = root->left;
          while (t->right)
            t = t->right;
          pre = t;
        }
        if (root->right)
        {
          Node *t = root->right;
          while (t->left)
            t = t->left;
          suc = t;
        }
        break;
      }
      else if (root->data < key)
      {
        pre = root;
        root = root->right;
      }
      else
      {
        suc = root;
        root = root->left;
      }
    }
    return {pre, suc};
  }
};
