#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // recursion
  int solve(int i, vector<int> &nums)
  {
    int n = nums.size();
    if (i >= n)
      return 0;
    int skip = solve(i + 1, nums);
    int take = nums[i] + solve(i + 2, nums);
    return max(skip, take);
  }
  int rob(vector<int> &nums)
  {
    return solve(0, nums);
  }
};
// memorized approach
class Solution
{
public:
  // memorization
  vector<int> dp;
  int solve(int i, vector<int> &nums)
  {
    int n = nums.size();
    if (i >= n)
      return 0;
    if (dp[i] != -1)
      return dp[i];
    int skip = solve(i + 1, nums);
    int take = nums[i] + solve(i + 2, nums);
    return dp[i] = max(skip, take);
  }
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    dp.resize(n + 1, -1);
    return solve(0, nums);
  }
};
// tabulation approach
class Solution
{
public:
  // tabulation
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
      int take = INT_MIN, skip = INT_MIN;
      take = nums[i] + dp[i - 2];
      skip = dp[i - 1];
      dp[i] = max(skip, take);
    }
    return dp[n - 1];
  }
};
// space optimized version
class Solution
{
public:
  // space optimized
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
      int take = nums[i] + prev2;
      int skip = prev1;
      int curr = max(skip, take);
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};
class Solution
{
public:
  // space optimized solution
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];
    int prev = nums[0];
    int prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
      int skip = prev1;
      int take = nums[i] + prev;
      int curr = max(skip, take);
      prev = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};