class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int n = word1.size(), m = word2.size();
    vector<int> dp(m + 1);
    for (int j = 0; j <= m; j++)
      dp[j] = j;
    for (int i = 1; i <= n; i++)
    {
      int prevDiag = dp[0];
      dp[0] = i;
      for (int j = 1; j <= m; j++)
      {
        int temp = dp[j];
        if (word1[i - 1] == word2[j - 1])
          dp[j] = prevDiag;
        else
          dp[j] = 1 + min(dp[j], dp[j - 1]);
        prevDiag = temp;
      }
    }
    return dp[m];
  }
};