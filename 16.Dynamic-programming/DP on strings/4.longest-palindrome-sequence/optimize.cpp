#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int longestPalindromeSubseq(string s)
  {
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      int prevDiag = 0;
      for (int j = 1; j <= n; j++)
      {
        int temp = dp[j];
        if (s[i - 1] == t[j - 1])
          dp[j] = 1 + prevDiag;
        else
          dp[j] = max(dp[j], dp[j - 1]);
        prevDiag = temp;
      }
    }
    return dp[n];
  }
};