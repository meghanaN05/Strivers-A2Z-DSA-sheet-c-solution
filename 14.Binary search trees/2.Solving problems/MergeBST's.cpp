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
// brute force

class BSTIterator
{
public:
  int i = 0;
  vector<int> ans;
  void inorder(TreeNode *root)
  {
    if (root == NULL)
      return;
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
  }
  BSTIterator(TreeNode *root)
  {
    inorder(root);
  }

  int next()
  {
    return ans[i++];
  }

  bool hasNext()
  {
    return i != ans.size();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
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
// optimsed solution
class BSTIterator
{
private:
  stack<TreeNode *> st;
  void pushLeft(TreeNode *node)
  {
    while (node)
    {
      st.push(node);
      node = node->left;
    }
  }

public:
  BSTIterator(TreeNode *root)
  {
    pushLeft(root);
  }
  int next()
  {
    TreeNode *curr = st.top();
    st.pop();
    if (curr->right)
      pushLeft(curr->right);
    return curr->val;
  }
  bool hasNext()
  {
    return !st.empty();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */