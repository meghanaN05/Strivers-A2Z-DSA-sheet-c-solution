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