#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // recursion approach
  int n;
  unordered_map<int, int> mp;
  int solve(vector<int> &stones, int curr, int prevJump)
  {
    if (curr == n - 1)
      return true;
    bool result = false;
    for (int i = prevJump - 1; i <= prevJump + 1; i++)
    {
      if (i > 0)
      {
        int nextstone = stones[curr] + i;
        if (mp.find(nextstone) != mp.end())
        {
          result = result || solve(stones, mp[nextstone], i);
        }
      }
    }
    return result;
  }
  bool canCross(vector<int> &stones)
  {
    n = stones.size();
    if (stones[1] != 1)
      return false;
    for (int i = 0; i < n; i++)
    {
      mp[stones[i]] = i;
    }
    return solve(stones, 0, 0);
  }
};
class Solution
{
public:
  // memorized approach
  int n;
  unordered_map<int, int> mp;
  vector<vector<int>> dp;
  int solve(vector<int> &stones, int curr, int prevJump)
  {
    if (curr == n - 1)
      return true;
    if (dp[curr][prevJump] != -1)
      return dp[curr][prevJump];
    bool result = false;
    for (int i = prevJump - 1; i <= prevJump + 1; i++)
    {
      if (i > 0)
      {
        int nextstone = stones[curr] + i;
        if (mp.find(nextstone) != mp.end())
        {
          result = result || solve(stones, mp[nextstone], i);
        }
      }
    }
    return dp[curr][prevJump] = result;
  }
  bool canCross(vector<int> &stones)
  {
    n = stones.size();
    dp.resize(n, vector<int>(n, -1));
    if (stones[1] != 1)
      return false;
    for (int i = 0; i < n; i++)
    {
      mp[stones[i]] = i;
    }
    return solve(stones, 0, 0);
  }
};
class Solution
{
public:
  // tabulation approach
  int n;
  unordered_map<int, int> mp;
  vector<vector<int>> dp;
  bool canCross(vector<int> &stones)
  {
    n = stones.size();
    if (stones[1] != 1)
      return false;
    for (int i = 0; i < n; i++)
    {
      mp[stones[i]] = i;
    }
    vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
    for (int j = 0; j <= n; j++)
    {
      dp[n - 1][j] = true;
    }
    for (int curr = n - 2; curr >= 0; curr--)
    {
      for (int prevJump = n; prevJump >= 0; prevJump--)
      {
        bool result = false;
        for (int i = prevJump - 1; i <= prevJump + 1; i++)
        {
          if (i > 0)
          {
            int nextstone = stones[curr] + i;
            if (mp.find(nextstone) != mp.end())
            {
              int nextIndex = mp[nextstone];
              if (i <= n)
              {
                result = result || dp[nextIndex][i];
              }
            }
          }
        }
        dp[curr][prevJump] = result;
      }
    }
    return dp[0][0];
  }
};
class Solution
{
public:
  // space optimized solution
  bool canCross(vector<int> &stones)
  {
    int n = stones.size();
    if (stones[1] != 1)
      return false;
    vector<unordered_set<int>> dp(n);
    dp[1].insert(1);
    for (int i = 1; i < n; i++)
    {
      for (int prevJump : dp[i])
      {
        for (int jump = prevJump - 1; jump <= prevJump + 1; jump++)
        {
          if (jump > 0)
          {
            int nextStone = stones[i] + jump;
            auto it = lower_bound(stones.begin() + i + 1, stones.end(), nextStone);
            if (it != stones.end() && *it == nextStone)
            {
              int nextIndex = distance(stones.begin(), it);
              dp[nextIndex].insert(jump);
            }
          }
        }
      }
    }
    return !dp[n - 1].empty();
  }
};