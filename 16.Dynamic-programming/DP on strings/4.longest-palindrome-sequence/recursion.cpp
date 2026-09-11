#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int dfs(int i, int j, string &s, string &t)
  {
    if (i == s.size() || j == t.size())
      return 0;
    if (s[i] == t[j])
      return 1 + dfs(i + 1, j + 1, s, t);
    return max(dfs(i + 1, j, s, t), dfs(i, j + 1, s, t));
  }

  int longestPalindromeSubseq(string s)
  {
    string t = s;
    reverse(t.begin(), t.end());
    return dfs(0, 0, s, t);
  }
};