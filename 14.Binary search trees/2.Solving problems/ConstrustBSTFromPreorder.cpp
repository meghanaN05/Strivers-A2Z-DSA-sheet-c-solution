#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  int i = 0;
  TreeNode *build(vector<int> &preorder, int maxi)
  {
    if (i == preorder.size() || preorder[i] > maxi)
      return NULL;
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = build(preorder, root->val);
    root->right = build(preorder, maxi);
    return root;
  }
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    TreeNode *ans = build(preorder, INT_MAX);
    return ans;
  }
};