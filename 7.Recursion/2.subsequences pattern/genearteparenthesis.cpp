#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<string> ans;
  void dfs(int i, int n, int open, string curr)
  {
    if (i == n)
    {
      if (open == 0)
        ans.push_back(curr);
      return;
    }
    dfs(i + 1, n, open + 1, curr + "(");
    if (open)
    {
      dfs(i + 1, n, open - 1, curr + ")");
    }
  }
  vector<string> generateParenthesis(int n)
  {
    dfs(0, 2 * n, 0, "");
    return ans;
  }
};
