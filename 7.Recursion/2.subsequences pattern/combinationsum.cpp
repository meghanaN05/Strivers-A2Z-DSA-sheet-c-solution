#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> ans;
  vector<int> curr;
  void dfs(int i, vector<int> &candidates, int target)
  {
    if (target == 0)
    {
      ans.push_back(curr);
      return;
    }
    if (i == candidates.size() || target < 0)
      return;
    dfs(i + 1, candidates, target);
    curr.push_back(candidates[i]);
    dfs(i, candidates, target - candidates[i]);
    curr.pop_back();
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    dfs(0, candidates, target);
    return ans;
  }
};
/*time complexity: O(2^n * n) space complexity: O(n)*/