#include <bits/stdc++.h>
using namespace std;
/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
  bool isleaf(Node *root)
  {
    return !root->left && !root->right;
  }
  void addleaves(Node *node, vector<int> &res)
  {
    if (!node)
      return;
    if (isleaf(node))
    {
      res.push_back(node->data);
      return;
    }
    addleaves(node->left, res);
    addleaves(node->right, res);
  }
  vector<int> boundaryTraversal(Node *root)
  {
    vector<int> ans;
    if (!root)
      return ans;
    if (!isleaf(root))
      ans.push_back(root->data);
    Node *curr = root->left;
    while (curr)
    {
      if (!isleaf(curr))
      {
        ans.push_back(curr->data);
      }
      if (curr->left)
        curr = curr->left;
      else
        curr = curr->right;
    }
    addleaves(root, ans);
    vector<int> right;
    curr = root->right;
    while (curr)
    {
      if (!isleaf(curr))
        right.push_back(curr->data);
      if (curr->right)
        curr = curr->right;
      else
        curr = curr->left;
    }
    reverse(right.begin(), right.end());
    for (int x : right)
      ans.push_back(x);

    return ans;
  }
};
/*time complexity:O(n) && space complexity:O(n)*/