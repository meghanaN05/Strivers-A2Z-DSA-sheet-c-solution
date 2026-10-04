#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    int size = n * m;
    unordered_map<int, int> mp;
    for (int i = 1; i <= size; i++)
    {
      mp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        mp[grid[i][j]]++;
      }
    }
    vector<int> ans(2, 0);
    for (auto it : mp)
    {
      if (it.second == 0)
        ans[1] = it.first;
      if (it.second == 2)
        ans[0] = it.first;
    }
    if (ans[1] == 0)
      ans[1] = size;
    return ans;
  }
};