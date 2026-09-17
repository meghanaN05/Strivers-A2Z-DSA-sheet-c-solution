#include <bits/stdc++.h>
using namespace std;
// uising one stack
class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    if (!root)
      return ans;
    stack<TreeNode *> st1;
    TreeNode *curr = root;
    TreeNode *lastvisited = nullptr;
    while (curr || !st1.empty())
    {
      while (curr)
      {
        st1.push(curr);
        curr = curr->left;
      }
      TreeNode *node = st1.top();
      if (node->right != NULL && lastvisited != node->right)
      {
        curr = node->right;
      }
      else
      {
        ans.push_back(node->val);
        lastvisited = node;
        st1.pop();
      }
    }

    return ans;
  }
};