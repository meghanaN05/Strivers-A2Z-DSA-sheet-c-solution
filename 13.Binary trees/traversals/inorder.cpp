#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void helper(TreeNode *root)
{
  if (root == NULL)
    return;
  helper(root->left);
  ans.push_back(root->val);
  helper(root->right);
}
vector<int> orderTraversal(TreeNode *root)
{
  ans.clear();
  helper(root);
  return ans;
}
/*time complexity: O(n), space complexity: O(h) where h is the height of the tree*/