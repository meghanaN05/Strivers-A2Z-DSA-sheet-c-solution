#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> bottomView(Node *root)
  {
    // code here
    vector<int> ans;
    if (!root)
      return ans;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while (!q.empty())
    {
      TreeNode *node = q.front().first;
      TreeNode *dist = q.front().second;
      q.pop();
      mp[dist] = node->val;
      if (node->left)
      {
        q.push({node->left, dist - 1});
      }
      if (node->right)
      {
        q.push({node->right, dist + 1});
      }
    }
    for (auto it : mp)
    {
      ans.push_back(it.second);
    }
    return ans;
  }
};
/*time complexity:O(n) && space complexity:O(n)*/