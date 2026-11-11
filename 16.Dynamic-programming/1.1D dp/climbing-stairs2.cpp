#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // recursion
  int solve(int i, vector<int> &costs)
  {
    int n = costs.size();
    if (i == n)
      return 0;
    int op1 = 0;
    if (i + 1 <= n)
    {
      op1 = solve(i + 1, costs) + costs[i] + (i + 1 - i) * (i + 1 - i);
    }
    int op2 = 1e9;
    if (i + 2 <= n)
    {
      op2 = solve(i + 2, costs) + costs[i + 1] + (i + 2 - i) * (i + 2 - i);
    }
    int op3 = 1e9;
    if (i + 3 <= n)
    {
      op3 = solve(i + 3, costs) + costs[i + 2] + (i + 3 - i) * (i + 3 - i);
    }
    return min(min(op1, op2), op3);
  }
  int climbStairs(int n, vector<int> &costs)
  {
    return solve(0, costs);
  }
};
class Solution
{
public:
  // memorized approach
  vector<int> dp;
  int solve(int i, vector<int> &costs)
  {
    int n = costs.size();
    if (i == n)
      return 0;
    if (dp[i] != -1)
      return dp[i];
    int op1 = 0;
    if (i + 1 <= n)
    {
      op1 = solve(i + 1, costs) + costs[i] + (i + 1 - i) * (i + 1 - i);
    }
    int op2 = 1e9;
    if (i + 2 <= n)
    {
      op2 = solve(i + 2, costs) + costs[i + 1] + (i + 2 - i) * (i + 2 - i);
    }
    int op3 = 1e9;
    if (i + 3 <= n)
    {
      op3 = solve(i + 3, costs) + costs[i + 2] + (i + 3 - i) * (i + 3 - i);
    }
    return dp[i] = min(min(op1, op2), op3);
  }
  int climbStairs(int n, vector<int> &costs)
  {
    dp.resize(n + 1, -1);
    return solve(0, costs);
  }
};