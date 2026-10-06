#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 4. Insert an element into BST
Node *insert(Node *root, int val)
{
  if (root == nullptr)
  {
    return new Node(val);
  }
  if (val < root->data)
  {
    root->left = insert(root->left, val);
  }
  else if (val > root->data)
  {
    root->right = insert(root->right, val);
  }
  return root;
}

// 1. Search an element in BST
void search(Node *root, int val)
{
  Node *curr = root;
  while (curr != nullptr)
  {
    if (curr->data == val)
    {
      cout << "Found\n";
      return;
    }
    else if (val < curr->data)
    {
      curr = curr->left;
    }
    else
    {
      curr = curr->right;
    }
  }
  cout << "NULL\n";
}

// 2. Find Max element in BST
void findMax(Node *root)
{
  if (root == nullptr)
  {
    cout << "NULL\n";
    return;
  }
  Node *curr = root;
  while (curr->right != nullptr)
  {
    curr = curr->right;
  }
  cout << curr->data << "\n";
}

// 3. Find Min element in BST
void findMin(Node *root)
{
  if (root == nullptr)
  {
    cout << "NULL\n";
    return;
  }
  Node *curr = root;
  while (curr->left != nullptr)
  {
    curr = curr->left;
  }
  cout << curr->data << "\n";
}

int main()
{
  // Optimizes C++ I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *root = nullptr;
  int choice, val;

  while (cin >> choice)
  {
    if (choice == 5)
    {
      break;
    }

    switch (choice)
    {
    case 1: // Search
      if (std::cin >> val)
      {
        search(root, val);
      }
      break;
    case 2: // Find Max
      findMax(root);
      break;
    case 3: // Find Min
      findMin(root);
      break;
    case 4: // Insert
      if (std::cin >> val)
      {
        root = insert(root, val);
      }
      break;
    default:
      break;
    }
  }

  return 0;
}