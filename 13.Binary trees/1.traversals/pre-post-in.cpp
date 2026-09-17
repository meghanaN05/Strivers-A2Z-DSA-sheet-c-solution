#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

// Preorder: Root -> Left -> Right
void preorder(TreeNode *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(TreeNode *root)
{
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(TreeNode *root)
{
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

int main()
{

  // Creating the tree
  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  // Preorder
  cout << "Preorder: ";
  preorder(root);

  // Inorder
  cout << "\nInorder: ";
  inorder(root);

  // Postorder
  cout << "\nPostorder: ";
  postorder(root);

  return 0;
}