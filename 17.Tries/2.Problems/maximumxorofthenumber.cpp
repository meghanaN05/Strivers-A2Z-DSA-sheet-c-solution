#include <bitset>/stdc++.h>
using namespace std;
class Solution
{
public:
  class Node
  {
  public:
    Node *links[2];
    Node()
    {
      links[0] = NULL;
      links[1] = NULL;
    }
    bool contains(int bit)
    {
      return links[bit] != NULL;
    }
    void put(int bit, Node *node)
    {
      links[bit] = node;
    }
    Node *get(int bit)
    {
      return links[bit];
    }
  };
  Node *root = new Node();
  void insert(int num)
  {
    Node *node = root;
    for (int i = 31; i >= 0; i--)
    {
      int bit = (num >> i) & 1;
      if (!node->contains(bit))
      {
        node->put(bit, new Node());
      }
      node = node->get(bit);
    }
  }
  int getMax(int num)
  {
    Node *node = root;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
      int bit = (num >> i) & 1;
      int opposite = 1 - bit;
      if (node->contains(opposite))
      {
        ans = ans | (1 << i);
        node = node->get(opposite);
      }
      else
      {
        node = node->get(bit);
      }
    }
    return ans;
  }
  int findMaximumXOR(vector<int> &nums)
  {
    for (int x : nums)
    {
      insert(x);
    }
    int maxi = 0;
    for (int x : nums)
    {
      maxi = max(maxi, getMax(x));
    }
    return maxi;
  }
};
/*
time complexity: O(N * 32) = O(N)
space complexity: O(N * 32) = O(N)
*/