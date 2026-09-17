#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int diameter = 0;
  int solve(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    int lh = solve(root->left);
    int rh = solve(root->right);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
  }
  int diameterOfBinaryTree(TreeNode *root)
  {
    int ans = solve(root);
    return diameter;
  }
};