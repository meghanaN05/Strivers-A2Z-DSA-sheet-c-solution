#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool possible(int mid, vector<int> &piles, int h)
  {
    long long hours = 0;
    for (auto x : piles)
    {
      hours += (x + mid - 1) / mid;
    }
    return hours <= h;
  }
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    int ans = 0;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (possible(mid, piles, h))
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