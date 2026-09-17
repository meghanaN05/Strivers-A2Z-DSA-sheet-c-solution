#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int dfs(int i, int j, string &s)
  {
    if (i >= j)
      return 0;
    if (s[i] == s[j])
      return dfs(i + 1, j - 1, s);
    return 1 + min(dfs(i + 1, j, s), dfs(i, j - 1, s));
  }

  int minInsertions(string s)
  {
    return dfs(0, s.size() - 1, s);
  }
};