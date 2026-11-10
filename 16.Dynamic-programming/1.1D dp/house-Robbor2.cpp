#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // recursion
  int solve(int i, int n, vector<int> &nums)
  {
    if (i > n)
      return 0;
    int skip = solve(i + 1, n, nums);
    int take = nums[i] + solve(i + 2, n, nums);
    return max(take, skip);
  }
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    int case1 = solve(0, n - 2, nums);
    int case2 = solve(1, n - 1, nums);
    return max(case1, case2);
  }
};
// memorized approach
class Solution
{
public:
  int solve(int i, int n, vector<int> &nums, vector<int> &memo)
  {
    if (i > n)
      return 0;
    if (memo[i] != -1)
      return memo[i];
    int skip = solve(i + 1, n, nums, memo);
    int take = nums[i] + solve(i + 2, n, nums, memo);
    return memo[i] = max(take, skip);
  }
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> memo1(n, -1);
    int case1 = solve(0, n - 2, nums, memo1);
    vector<int> memo2(n, -1);
    int case2 = solve(1, n - 1, nums, memo2);
    return max(case1, case2);
  }
};
// tabulation approach
class Solution
{
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> dp1(n, 0);
    dp1[0] = nums[0];
    for (int i = 1; i < n - 1; i++)
    {
      int take = nums[i];
      if (i > 1)
        take += dp1[i - 2];
      int skip = dp1[i - 1];
      dp1[i] = max(take, skip);
    }
    vector<int> dp2(n, 0);
    dp2[1] = nums[1];
    for (int i = 2; i < n; i++)
    {
      int take = nums[i];
      if (i > 2)
        take += dp2[i - 2];
      int skip = dp2[i - 1];
      dp2[i] = max(take, skip);
    }
    return max(dp1[n - 2], dp2[n - 1]);
  }
};
// space optimized approach
class Solution
{
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    int prev1 = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n - 1; i++)
    {
      int take = nums[i] + prev2;
      int skip = prev1;
      int curr = max(take, skip);
      prev2 = prev1;
      prev1 = curr;
    }
    int case1 = prev1;

    prev1 = nums[1];
    prev2 = 0;
    for (int i = 2; i < n; i++)
    {
      int take = nums[i] + prev2;
      int skip = prev1;
      int curr = max(take, skip);
      prev2 = prev1;
      prev1 = curr;
    }
    int case2 = prev1;

    return max(case1, case2);
  }
};