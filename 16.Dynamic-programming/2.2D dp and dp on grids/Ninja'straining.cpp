#include <bits/stdc++.h>
using namespace std;
// recursion approach
class Solution
{
public:
  int solve(int day, int last, vector<vector<int>> &arr)
  {
    int n = arr.size();
    if (day == n)
      return 0;
    int maxi = 0;
    for (int activity = 0; activity < 3; activity++)
    {
      if (activity != last)
      {
        int points = arr[day][activity] + solve(day + 1, activity, arr);
        maxi = max(maxi, points);
      }
    }
    return maxi;
  }

  int maximumPoints(vector<vector<int>> &arr)
  {
    int n = arr.size();
    return solve(0, 3, arr);
  }
};
class Solution
{
public:
  // memorization code
  int n;
  int m;
  vector<vector<int>> dp;
  int solve(int i, int last, vector<vector<int>> &mat)
  {
    if (i == n)
      return 0;
    if (dp[i][last] != -1)
      return dp[i][last];
    int maxi = 0;
    for (int j = 0; j < 3; j++)
    {
      if (j != last)
      {
        int points = solve(i + 1, j, mat) + mat[i][j];
        maxi = max(maxi, points);
      }
    }
    return dp[i][last] = maxi;
  }
  int maximumPoints(vector<vector<int>> &mat)
  {
    n = mat.size(), m = mat[0].size();
    dp.resize(n, vector<int>(4, -1));
    return solve(0, 3, mat);
  }
};
