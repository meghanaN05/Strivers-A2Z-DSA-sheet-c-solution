#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool func(int ind, int sum, std::vector<int> &nums)
  {
    if (ind == nums.size())
    {
      return sum == 0;
    }
    return func(ind + 1, sum - nums[ind], nums) | func(ind + 1, sum, nums);
  }

public:
  bool checkSubsequenceSum(std::vector<int> &nums, int target)
  {
    return func(0, target, nums);
  }
};

/*time complexity: O(2^n) space complexity: O(n)*/