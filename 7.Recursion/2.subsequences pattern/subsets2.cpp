#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> ans;
  vector<int> curr;
  void helper(int i, vector<int> &nums)
  {
    if (i == nums.size())
    {
      ans.push_back(curr);
      return;
    }
    curr.push_back(nums[i]);
    helper(i + 1, nums);
    curr.pop_back();
    while (i + 1 < nums.size() && nums[i] == nums[i + 1])
    {
      i++;
    }
    helper(i + 1, nums);
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    helper(0, nums);
    return ans;
  }
};
/*time complexity: O(2^n * n) space complexity: O(2^n * n)*/