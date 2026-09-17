#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> dp;
  map<pair<int, int>, set<string>> memo;
  set<string> solve(int i, int j, string &s1, string &s2)
  {

    if (i == s1.size() || j == s2.size())
      return {""};

    if (memo.count({i, j}))
      return memo[{i, j}];

    set<string> res;

    if (s1[i] == s2[j])
    {

      auto temp = solve(i + 1, j + 1, s1, s2);

      for (auto &x : temp)
        res.insert(s1[i] + x);
    }
    else
    {

      if (dp[i + 1][j] >= dp[i][j + 1])
      {

        auto temp = solve(i + 1, j, s1, s2);
        res.insert(temp.begin(), temp.end());
      }

      if (dp[i][j + 1] >= dp[i + 1][j])
      {

        auto temp = solve(i, j + 1, s1, s2);
        res.insert(temp.begin(), temp.end());
      }
    }

    return memo[{i, j}] = res;
  }

  vector<string> allLCS(string &s1, string &s2)
  {

    int n = s1.size();
    int m = s2.size();
    dp.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {

        if (s1[i] == s2[j])
          dp[i][j] = 1 + dp[i + 1][j + 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }

    if (dp[0][0] == 0)
      return {""};

    auto ans = solve(0, 0, s1, s2);

    return vector<string>(ans.begin(), ans.end());
  }
};