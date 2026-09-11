#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int longestCommonSubstr(string s1, string s2)
  {

    int n = s1.size();
    int m = s2.size();

    vector<int> dp(m + 1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {

      int prevDiagonal = 0;

      for (int j = 1; j <= m; j++)
      {

        int temp = dp[j];

        if (s1[i - 1] == s2[j - 1])
        {

          dp[j] = 1 + prevDiagonal;
          ans = max(ans, dp[j]);
        }
        else
        {

          dp[j] = 0;
        }

        prevDiagonal = temp;
      }
    }

    return ans;
  }
};