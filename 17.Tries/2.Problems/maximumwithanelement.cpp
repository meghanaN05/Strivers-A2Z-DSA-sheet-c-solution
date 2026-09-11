#include <bits/stdc++.h>
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
    Node *get(int bit)
    {
      return links[bit];
    }
    void put(int bit, Node *node)
    {
      links[bit] = node;
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
    int ans = 0;
    Node *node = root;
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
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> q;
    for (int i = 0; i < queries.size(); i++)
    {
      q.push_back({queries[i][1], queries[i][0], i});
    }
    sort(q.begin(), q.end());
    vector<int> ans(queries.size(), -1);
    int j = 0;
    for (auto q : q)
    {
      int mi = q[0];
      int xi = q[1];
      int i = q[2];
      while (j < nums.size() && nums[j] <= mi)
      {
        insert(nums[j]);
        j++;
      }
      if (j > 0)
      {
        ans[i] = getMax(xi);
      }
    }
    return ans;
  }
};
/*
time complexity: O(N * 32 + Q * 32 * log N) = O(N * 32 + Q * 32 * log N)
space complexity: O(N * 32) = O(N * 32)
*/