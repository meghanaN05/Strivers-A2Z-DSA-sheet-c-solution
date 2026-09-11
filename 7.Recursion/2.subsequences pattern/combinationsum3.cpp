#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> ans;
  vector<int> curr;
  void helper(int i, vector<int> &nums, int k, int n)
  {
    if (n == 0 && k == 0)
    {
      ans.push_back(curr);
      return;
    }
    if (n < 0 || k < 0 || i >= nums.size())
      return;
    curr.push_back(nums[i]);
    helper(i + 1, nums, k - 1, n - nums[i]);
    curr.pop_back();
    helper(i + 1, nums, k, n);
  }
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    helper(0, nums, k, n);
    return ans;
  }
};
/*time complexity: O(2^n * n) space complexity: O(n)*/