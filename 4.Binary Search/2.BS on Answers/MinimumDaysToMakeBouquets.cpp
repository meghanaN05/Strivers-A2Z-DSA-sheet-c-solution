#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool possible(int day, vector<int> &bloomDay, int m, int k)
  {
    int b = 0, f = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
      if (bloomDay[i] <= day)
      {
        f++;
        if (f == k)
        {
          b++;
          f = 0;
        }
      }
      else
      {
        f = 0;
      }
    }
    return b >= m;
  }
  int minDays(vector<int> &bloomDay, int m, int k)
  {
    if (1LL * m * k > bloomDay.size())
      return -1;
    int l = *min_element(bloomDay.begin(), bloomDay.end());
    int r = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (possible(mid, bloomDay, m, k))
      {
        ans = mid;
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    return ans;
  }
};