#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> dp;

  int dfs(int i, int j, string &s, string &t)
  {
    if (i == s.size() || j == t.size())
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == t[j])
      return dp[i][j] = 1 + dfs(i + 1, j + 1, s, t);
    return dp[i][j] = max(dfs(i + 1, j, s, t), dfs(i, j + 1, s, t));
  }

  int longestPalindromeSubseq(string s)
  {
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    dp.assign(n, vector<int>(n, -1));
    return dfs(0, 0, s, t);
  }
};