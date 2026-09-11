#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int dfs(int i, int j, int count, string &s1, string &s2)
  {

    if (i == s1.size() || j == s2.size())
      return count;

    int ans = count;

    if (s1[i] == s2[j])
      ans = dfs(i + 1, j + 1, count + 1, s1, s2);
    ans = max(ans, dfs(i + 1, j, 0, s1, s2));
    ans = max(ans, dfs(i, j + 1, 0, s1, s2));
    return ans;
  }

  int longestCommonSubstr(string s1, string s2)
  {

    return dfs(0, 0, 0, s1, s2);
  }
};