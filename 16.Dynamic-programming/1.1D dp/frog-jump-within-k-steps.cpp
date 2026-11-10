#include <bits/stdc++.h>
using namespace std;
class Solution
{
  int solve(int i, vector<int> &heights, int k)
  {
    if (i == 0)
      return 0;

    int minEnergy = INT_MAX;
    for (int j = 1; j <= k; ++j)
    {
      if (i - j >= 0)
      {
        int jumpCost = solve(i - j, heights, k) + abs(heights[i] - heights[i - j]);
        minEnergy = min(minEnergy, jumpCost);
      }
    }
    return minEnergy;
  }

public:
  int frogJump(vector<int> &heights, int k)
  {
    int n = heights.size();
    return solve(n - 1, heights, k);
  }
};
// memorization approach
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

class Solution
{
  int solve(int i, vector<int> &heights, int k, vector<int> &dp)
  {
    if (i == 0)
      return 0;
    if (dp[i] != -1)
      return dp[i];

    int minEnergy = INT_MAX;
    for (int j = 1; j <= k; ++j)
    {
      if (i - j >= 0)
      {
        int jumpCost = solve(i - j, heights, k, dp) + abs(heights[i] - heights[i - j]);
        minEnergy = min(minEnergy, jumpCost);
      }
    }
    return dp[i] = minEnergy;
  }

public:
  int frogJump(vector<int> &heights, int k)
  {
    int n = heights.size();
    vector<int> dp(n, -1);
    return solve(n - 1, heights, k, dp);
  }
};
// tabulation code

class Solution
{
public:
  int frogJump(vector<int> &heights, int k)
  {
    int n = heights.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; ++i)
    {
      for (int j = 1; j <= k; ++j)
      {
        if (i - j >= 0)
        {
          dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
        }
      }
    }
    return dp[n - 1];
  }
};
// space optimization
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

class Solution
{
public:
  int frogJump(vector<int> &heights, int k)
  {
    int n = heights.size();
    // Sliding window array to keep track of the last k values
    vector<int> dp(k, 0);

    for (int i = 1; i < n; ++i)
    {
      int minEnergy = INT_MAX;
      for (int j = 1; j <= k; ++j)
      {
        if (i - j >= 0)
        {
          minEnergy = min(minEnergy, dp[(i - j) % k] + abs(heights[i] - heights[i - j]));
        }
      }
      dp[i % k] = minEnergy;
    }
    return dp[(n - 1) % k];
  }
};