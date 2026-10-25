#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  TreeNode *map_parents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, int target)
  {
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *targetNode = nullptr;

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      if (node->val == target)
        targetNode = node;
      if (node->left)
      {
        parent[node->left] = node;
        q.push(node->left);
      }
      if (node->right)
      {
        parent[node->right] = node;
        q.push(node->right);
      }
    }

    return targetNode;
  }

  int amountOfTime(TreeNode *root, int target)
  {
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_map<TreeNode *, bool> visited;
    TreeNode *targetNode = map_parents(root, parent, target);
    queue<TreeNode *> q;
    q.push(targetNode);
    visited[targetNode] = true;
    int level = -1;

    while (!q.empty())
    {
      int size = q.size();
      while (size--)
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

    return level;
  }
};