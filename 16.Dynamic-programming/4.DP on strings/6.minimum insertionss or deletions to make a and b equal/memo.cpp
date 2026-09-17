
class Solution
{
public:
  vector<vector<int>> dp;
  int dfs(int i, int j, string &s, string &t)
  {
    if (i == s.size())
      return t.size() - j;
    if (j == t.size())
      return s.size() - i;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == t[j])
      return dp[i][j] = dfs(i + 1, j + 1, s, t);
    return dp[i][j] = 1 + min(dfs(i + 1, j, s, t), dfs(i, j + 1, s, t));
  }
  int minDistance(string word1, string word2)
  {
    dp.assign(word1.size(), vector<int>(word2.size(), -1));
    return dfs(0, 0, word1, word2);
  }
};