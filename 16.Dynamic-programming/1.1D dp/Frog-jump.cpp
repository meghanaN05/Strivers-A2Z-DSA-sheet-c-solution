#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int f(int index, vector<int> &height)
  {
    if (index == height.size() - 1)
      return 0;
    int one = f(index + 1, height) +
              abs(height[index + 1] - height[index]);
    int two = 1e9;
    if (index + 2 < height.size())
      two = f(index + 2, height) +
            abs(height[index + 2] - height[index]);

    return min(one, two);
  }

  int minCost(vector<int> &height)
  {
    return f(0, height);
  }
};
// memorized approach
class Solution
{
public:
  vector<int> dp;
  int f(int index, vector<int> &height)
  {
    if (index == height.size() - 1)
      return 0;
    if (dp[index] != -1)
      return dp[index];
    int one = f(index + 1, height) +
              abs(height[index + 1] - height[index]);
    int two = 1e9;
    if (index + 2 < height.size())
      two = f(index + 2, height) +
            abs(height[index + 2] - height[index]);

    return dp[index] = min(one, two);
  }

  int minCost(vector<int> &height)
  {
    dp.resize(height.size(), -1);
    return f(0, height);
  }
};
// tabulation approach
class Solution
{
public:
  int minCost(vector<int> &height)
  {
    vector<int> dp(height.size(), 0);
    dp[0] = 0;
    for (int i = 1; i < height.size(); i++)
    {
      int one = dp[i - 1] + abs(height[i] - height[i - 1]);
      int two = 1e9;
      if (i > 1)
        two = dp[i - 2] + abs(height[i] - height[i - 2]);
      dp[i] = min(one, two);
    }
    return dp[height.size() - 1];
  }
};
// space optimized version
class Solution
{
public:
  int minCost(vector<int> &height)
  {
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < height.size(); i++)
    {
      int one = prev + abs(height[i] - height[i - 1]);
      int two = 1e9;
      if (i > 1)
        two = prev2 + abs(height[i] - height[i - 2]);
      int curr = min(one, two);
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
};