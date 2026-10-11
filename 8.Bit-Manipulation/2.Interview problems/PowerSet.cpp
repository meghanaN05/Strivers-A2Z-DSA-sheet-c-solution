#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> ans;
  vector<int> curr;
  void dfs(int i, int n, vector<int> &nums)
  {
    if (i == n)
    {
      ans.push_back(curr);
      return;
    }
    curr.push_back(nums[i]);
    dfs(i + 1, n, nums);
    curr.pop_back();
    dfs(i + 1, n, nums);
  }
  vector<vector<int>> subsets(vector<int> &nums)
  {
    int n = nums.size();
    dfs(0, n, nums);
    return ans;
  }
};
class Solution
{
public:
  // using bit manipulation technique(1<<n possibilities)
  vector<vector<int>> subsets(vector<int> &nums)
  {
    int n = nums.size();
    int ts = 1 << n;
    vector<vector<int>> ans;
    for (int i = 0; i < ts; i++)
    {
      vector<int> curr;
      for (int j = 0; j < n; j++)
      {
        if ((i & (1 << j)) != 0)
          curr.push_back(nums[j]);
      }
      ans.push_back(curr);
    }
    return ans;
  }
};