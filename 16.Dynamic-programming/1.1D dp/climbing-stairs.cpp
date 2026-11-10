#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // recursion
  int solve(int n)
  {
    if (n <= 3)
      return n;
    return solve(n - 1) + solve(n - 2);
  }
  int climbStairs(int n)
  {
    return solve(n);
  }
};

class Solution
{
public:
  // memorized approach
  vector<int> dp;
  int solve(int n)
  {
    if (n <= 3)
      return n;
    if (dp[n] != -1)
      return dp[n];
    return dp[n] = solve(n - 1) + solve(n - 2);
  }
  int climbStairs(int n)
  {
    dp.resize(n + 1, -1);
    return solve(n);
  }
};
class Solution
{
public:
  // tabulation approach
  int climbStairs(int n)
  {
    if (n <= 1)
      return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
class Solution
{
public:
  // space optimized version
  int climbStairs(int n)
  {
    if (n <= 2)
      return n;
    int prev1 = 1;
    int prev2 = 2;
    int curr = 0;
    for (int i = 3; i <= n; i++)
    {
      curr = prev1 + prev2;
      prev1 = prev2;
      prev2 = curr;
    }
    return prev2;
  }
};