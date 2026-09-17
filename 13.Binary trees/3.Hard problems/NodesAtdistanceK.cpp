#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  void map_parents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
  {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
      {
        q.push(node->left);
        parent[node->left] = node;
      }
      if (node->right)
      {
        q.push(node->right);
        parent[node->right] = node;
      }
    }
  }
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    unordered_map<TreeNode *, TreeNode *> parent;
    map<TreeNode *, bool> visited;
    map_parents(root, parent);
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int level = 0;
    while (!q.empty())
    {
      int size = q.size();
      if (level == k)
        break;
      for (int i = 0; i < size; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        if (node->left && !visited[node->left])
        {
          visited[node->left] = true;
          q.push(node->left);
        }
        if (node->right && !visited[node->right])
        {
          visited[node->right] = true;
          q.push(node->right);
        }
        if (parent.count(node) && !visited[parent[node]])
        {
          visited[parent[node]] = true;
          q.push(parent[node]);
        }
      }
      level++;
    }
    vector<int> ans;
    while (!q.empty())
    {
      ans.push_back(q.front()->val);
      q.pop();
    }

    return ans;
  }
};