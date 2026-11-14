#include <bits/stdc++.h>
using namespace std;
// recusion code
class Solution
{
public:
  int solve(int m, int n, int i, int j)
  {
    if (i >= n || j >= m)
      return 0;
    if (i == n - 1 || j == m - 1)
      return 1;
    return solve(m, n, i + 1, j) + solve(m, n, i, j + 1);
  }
  int uniquePaths(int m, int n)
  {
    return solve(m, n, 0, 0);
  }
};
class Solution
{
public:
  // memorization code
  vector<vector<int>> dp;
  int solve(int m, int n, int i, int j)
  {
    if (i >= n || j >= m)
      return 0;
    if (i == n - 1 || j == m - 1)
      return 1;
    if (dp[i][j] != -1)
      return dp[i][j];
    return dp[i][j] = solve(m, n, i + 1, j) + solve(m, n, i, j + 1);
  }
  int uniquePaths(int m, int n)
  {
    dp.resize(n, vector<int>(m, -1));
    return solve(m, n, 0, 0);
  }
};
// tabulation code
