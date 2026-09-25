#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int mini = prices[0];
    int diff = 0;
    for (int i = 1; i < prices.size(); i++)
    {
      if (prices[i] < mini)
      {
        mini = prices[i];
      }
      diff = max(diff, prices[i] - mini);
    }
    return diff;
  }
};