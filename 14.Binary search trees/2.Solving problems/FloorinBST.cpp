// Function to search a node in BST.
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
  int floor(Node *root, int x)
  {
    // Code here
    int floor = -1;
    while (root != NULL)
    {
      if (root->data == x)
      {
        floor = root->data;
        return floor;
      }
      if (x < root->data)
      {
        root = root->left;
      }
      else
      {
        floor = root->data;
        root = root->right;
      }
    }
    return floor;
  }
};
/*tc: O(log n)
sc: O(1) */