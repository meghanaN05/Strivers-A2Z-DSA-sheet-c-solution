#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<vector<int>>> dp;

  int dfs(int i, int j, int count, string &s1, string &s2)
  {

    if (i == s1.size() || j == s2.size())
      return count;

    if (dp[i][j][count] != -1)
      return dp[i][j][count];

    int ans = count;

    if (s1[i] == s2[j])
      ans = dfs(i + 1, j + 1, count + 1, s1, s2);

    ans = max(ans, dfs(i + 1, j, 0, s1, s2));
    ans = max(ans, dfs(i, j + 1, 0, s1, s2));

    return dp[i][j][count] = ans;
  }

  int longestCommonSubstr(string s1, string s2)
  {

    int n = s1.size();
    int m = s2.size();

    dp.assign(n,
              vector<vector<int>>(m,
                                  vector<int>(min(n, m) + 1, -1)));

    return dfs(0, 0, 0, s1, s2);
  }
};