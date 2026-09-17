#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  set<string> ans;

  void solve(int i, int j, string &s1, string &s2, string cur)
  {

    if (i == s1.size() || j == s2.size())
    {
      ans.insert(cur);
      return;
    }

    if (s1[i] == s2[j])
    {
      solve(i + 1, j + 1, s1, s2, cur + s1[i]);
    }
    else
    {
      solve(i + 1, j, s1, s2, cur);
      solve(i, j + 1, s1, s2, cur);
    }
  }

  vector<string> allLCS(string &s1, string &s2)
  {

    solve(0, 0, s1, s2, "");

    return vector<string>(ans.begin(), ans.end());
  }
};