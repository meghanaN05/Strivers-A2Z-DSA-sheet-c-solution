#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int divide(int dividend, int divisor)
  {
    // Handle integer overflow edge case
    if (dividend == INT_MIN && divisor == -1)
      return INT_MAX;

    // Determine result sign and work with positive values
    bool isNegative = (dividend < 0) ^ (divisor < 0);
    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
    long long ans = 0;

    // Exponential subtraction using bit shifts
    while (n >= d)
    {
      long long temp = d, count = 1;
      while (n >= (temp << 1))
      {
        temp <<= 1;
        count <<= 1;
      }
      n -= temp;
      ans += count;
    }

    return isNegative ? -ans : ans;
  }
};