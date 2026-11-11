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