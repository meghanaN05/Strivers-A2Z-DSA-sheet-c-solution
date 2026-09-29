#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // subarray problem
  int solve(vector<int> &nums, int goal)
  {
    if (goal < 0)
      return 0;
    int l = 0;
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      while (sum > goal)
      {
        sum -= nums[l];
        l++;
      }
      maxi += i - l + 1;
    }
    return maxi;
  }
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    return solve(nums, goal) - solve(nums, goal - 1);
  }
};
