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
// tabulation code
class Solution
{
public:
  int maximumPoints(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(mat[0][1], mat[0][2]);
    dp[0][1] = max(mat[0][0], mat[0][2]);
    dp[0][2] = max(mat[0][1], mat[0][0]);
    dp[0][3] = max(mat[0][1], max(mat[0][2], mat[0][0]));
    for (int i = 1; i < n; i++)
    {
      for (int last = 0; last < 4; last++)
      {
        dp[i][last] = 0;
        for (int task = 0; task < 3; task++)
        {
          if (task != last)
          {
            int points = mat[i][task] + dp[i - 1][task];
            dp[i][last] = max(dp[i][last], points);
          }
        }
      }
    }
    return dp[n - 1][3];
  }
};
// space optimization
class Solution
{
public:
  int maximumPoints(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> prev(4, 0);
    prev[0] = max(mat[0][1], mat[0][2]);
    prev[1] = max(mat[0][0], mat[0][2]);
    prev[2] = max(mat[0][1], mat[0][0]);
    prev[3] = max(mat[0][1], max(mat[0][2], mat[0][0]));
    for (int i = 1; i < n; i++)
    {
      vector<int> temp(4, 0);
      for (int last = 0; last < 4; last++)
      {
        temp[last] = 0;
        for (int task = 0; task < 3; task++)
        {
          if (task != last)
          {
            int points = mat[i][task] + prev[task];
            temp[last] = max(temp[last], points);
          }
        }
      }
      prev = temp;
    }
    return prev[3];
  }
};