#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void helper(TreeNode *root, vector<int> &ans)
  {
    if (root == NULL)
      return;
    ans.push_back(root->val);
    helper(root->left, ans);
    helper(root->right, ans);
  }
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    helper(root, ans);
    return ans;
  }
};
/*time complexity: O(n), space complexity: O(h) where h is the height of the tree*/
