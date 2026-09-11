#include <bit/stdc++.h>
using namespace std;
class Solution
{
public:
  double solve(double x, long long n)
  {
    if (n == 0)
      return 1;
    double ans = solve(x, n / 2);
    ans *= ans;
    if (n % 2 == 1)
      ans *= x;
    return ans;
  }
  double myPow(double x, int n)
  {
    long long N = n;
    if (n < 0)
    {
      x = 1 / x;
      N = -N;
    }
    return solve(x, N);
  }
};
/*time complexity: O(logn), space complexity: O(logn)*/