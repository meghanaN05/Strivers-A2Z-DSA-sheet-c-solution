class Solution
{
public:
  int dfs(int i, int j, string &s, string &t)
  {
    if (i == s.size())
      return t.size() - j;
    if (j == t.size())
      return s.size() - i;
    if (s[i] == t[j])
      return dfs(i + 1, j + 1, s, t);
    return 1 + min(dfs(i + 1, j, s, t), dfs(i, j + 1, s, t));
  }
  int minDistance(string word1, string word2)
  {
    return dfs(0, 0, word1, word2);
  }
};