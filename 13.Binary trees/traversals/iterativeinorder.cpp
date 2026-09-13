#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {

    vector<int> ans;
    TreeNode *curr = root;
    stack<TreeNode *> st;
    while (curr != NULL && !st.empty())
    {
      while (!curr)
      {
        st.pus(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();
      ans.push_back(curr->val);
      curr = curr->right;
    }
    return ans;
  }
}
/* time complexity: O(n), space complexity: O(h) where h is the height of the tree */