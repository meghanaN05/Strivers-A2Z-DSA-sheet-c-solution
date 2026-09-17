#include <bits/stdc++.h>
using namespace std;
/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution
{
public:
  vector<vector<int>> ans;
  vector<int> level;
  void dfs(Node *root)
  {
    if (root == NULL)
      return;
    level.push_back(root->data);
    if (!root->left && !root->right)
    {
      ans.push_back(level);
    }
    else
    {
      dfs(root->left);
      dfs(root->right);
    }
    level.pop_back();
  }
  vector<vector<int>> paths(Node *root)
  {
    dfs(root);
    return ans;
  }
};
/*time complexity:0(n) && space complexity:O(H)*/