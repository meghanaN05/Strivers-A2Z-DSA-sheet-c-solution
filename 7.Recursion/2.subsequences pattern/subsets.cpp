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
/*time complexity: O(2^n ) space complexity: O(2^n )*/