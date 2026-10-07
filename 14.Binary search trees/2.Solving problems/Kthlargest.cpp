#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> order;
  void inorder(Node *root)
  {
    if (!root)
      return;
    inorder(root->left);
    order.push_back(root->data);
    inorder(root->right);
  }
  int kthLargest(Node *root, int k)
  {
    inorder(root);
    reverse(order.begin(), order.end());
    return order[k - 1];
  }
};
// optimized solution
// tc: O(n) sc: O(h)
class Solution
{
public:
  void reverseInorder(Node *root, int k, int &count, int &ans)
  {
    // Stop recursion early if node is null or answer is already found
    if (!root || count >= k)
      return;

    // 1. Traverse Right Subtree First (Descending Order)
    reverseInorder(root->right, k, count, ans);

    // 2. Process Current Node
    count++;
    if (count == k)
    {
      ans = root->data;
      return;
    }

    // 3. Traverse Left Subtree
    reverseInorder(root->left, k, count, ans);
  }

  int Kthlargest(Node *root, int k)
  {
    int ans = -1;
    int count = 0; // Local variable reset for every function call
    reverseInorder(root, k, count, ans);
    return ans;
  }
};