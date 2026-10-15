#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int f(int mid, int n)
  {
    long long ans = 1;
    while (n > 0)
    {
      if (n % 2 == 1)
      {
        ans = ans * mid;
        n = n - 1;
      }
      else
      {
        mid = mid * mid;
        n = n / 2;
      }
    }
    return ans;
  }
  int nthRoot(int n, int m)
  {
    // Code here.
    int l = 0;
    int h = m;
    while (l <= h)
    {
      int mid = l + (h - l) / 2;
      int midN = f(mid, n);
      if (midN == m)
        return mid;
      else if (midN < m)
        l = mid + 1;
      else
        h = mid - 1;
    }
    return -1;
  }
};