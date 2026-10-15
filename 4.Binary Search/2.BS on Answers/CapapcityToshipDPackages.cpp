#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool possible(int mid, vector<int> &weights, int days)
  {
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < weights.size(); i++)
    {
      if (sum + weights[i] > mid)
      {
        cnt++;
        sum = 0;
      }
      sum += weights[i];
    }
    return cnt <= days;
  }
  int shipWithinDays(vector<int> &weights, int days)
  {
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);
    int ans = -1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if ((possible(mid, weights, days)))
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