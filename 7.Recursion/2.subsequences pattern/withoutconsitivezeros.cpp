#include <bits/stdc++.h>
using namepace std;
class Solution
{
public:
  vector<string> ans;
  void solve(int n, string curr, int last)
  {
    if (curr.size() == n)
    {
      ans.push_back(curr);
      return;
    }
    if (last != 0)
      solve(n, curr + '0', 0);
    solve(n, curr + '1', 1);
  }
  vector<string> validStrings(int n)
  {
    solve(n, "", 1);
    return ans;
  }
};
/*time complexity: O(2^n) space complexity: O(n)*/