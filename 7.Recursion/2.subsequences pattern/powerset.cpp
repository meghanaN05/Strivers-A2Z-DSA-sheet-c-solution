#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<string> ans;
  void solve(string s, int i, string curr)
  {
    if (i == s.size())
    {
      ans.push_back(curr);
      return;
    }
    solve(s, i + 1, curr);
    solve(s, i + 1, curr + s[i]);
  }
  vector<string> powerSet(string &s)
  {
    // Code here
    solve(s, 0, "");
    sort(ans.begin(), ans.end());
    return ans;
  }
};
/*time complexity: O(2^n * n) space complexity: O(2^n * n)*/
