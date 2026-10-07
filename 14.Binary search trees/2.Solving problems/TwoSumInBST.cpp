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
// brute force approach
class Solution
{
public:
  bool findTarget(TreeNode *root, int k)
  {
    vector<int> nums;
    inorder(root, nums);
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
      int sum = nums[left] + nums[right];
      if (sum == k)
      {
        return true;
      }
      else if (sum < k)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
    return false;
  }

private:
  void inorder(TreeNode *node, vector<int> &nums)
  {
    if (!node)
      return;
    inorder(node->left, nums);
    nums.push_back(node->val);
    inorder(node->right, nums);
  }
};
class Solution
{
public:
  // optimized solution
  unordered_set<int> seen;
  bool dfs(TreeNode *root, int k)
  {
    if (!root)
      return false;
    if (seen.count(k - root->val))
      return true;
    seen.insert(root->val);
    return dfs(root->left, k) ||
           dfs(root->right, k);
  }
  bool findTarget(TreeNode *root, int k)
  {
    return dfs(root, k);
  }
};