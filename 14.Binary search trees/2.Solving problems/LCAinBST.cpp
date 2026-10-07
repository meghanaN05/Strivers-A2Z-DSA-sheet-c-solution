#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root)
      return NULL;
    int curr = root->val;
    if (curr < p->val && curr < q->val)
    {
      return lowestCommonAncestor(root->right, p, q);
    }
    if (curr > p->val && curr > q->val)
    {
      return lowestCommonAncestor(root->left, p, q);
    }
    return root;
    // other method
    if (!root || root == p || root == q)
      return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
      return root;

    return left ? left : right;
  }
};