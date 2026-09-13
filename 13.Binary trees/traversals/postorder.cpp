#include <bits/stdc++.h>
using namespace std;
void helper(Node *root, vector<int> &ans)
{
  if (root == NULL)
    return;
  helper(root->left, ans);
  helper(root->right, ans);
  ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
  vector<int> ans;
  helper(root, ans);
  return ans;
}
/*time complexity: O(n), space complexity: O(h) where h is the height of the tree*/