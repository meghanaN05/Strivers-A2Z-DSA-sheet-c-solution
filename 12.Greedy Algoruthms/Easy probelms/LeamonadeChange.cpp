#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool lemonadeChange(vector<int> &bills)
  {
    int cnt5 = 0;
    int cnt10 = 0;
    int cnt20 = 0;
    for (int i = 0; i < bills.size(); i++)
    {
      if (bills[i] == 5)
        cnt5++;
      else if (bills[i] == 10)
      {
        cnt10++;
        if (cnt5 > 0)
        {
          cnt5--;
          continue;
        }
        return false;
      }
      else
      {
        cnt20++;
        if (cnt10 > 0 && cnt5 > 0)
        {
          cnt10--;
          cnt5--;
          continue;
        }
        if (cnt5 >= 3)
        {
          cnt5 -= 3;
          continue;
        }
        return false;
      }
    }
    return true;
  }
};
/*time complexity:O(n) && space complexity:O(1)*/