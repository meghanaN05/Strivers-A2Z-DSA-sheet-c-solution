#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  long long MOD = 1e9 + 7;
  double solve(long long x, long long n)
  {
    if (n == 0)
      return 1;
    long long ans = solve(x, n / 2);
    ans = (ans * ans) % MOD;
    if (n % 2 == 1)
      ans = (ans * x) % MOD;
    return ans;
  }
  int countGoodNumbers(long long n)
  {
    long long a = solve(5, (n + 1) / 2);
    long long b = solve(4, n / 2);
    return (a * b) % MOD;
  }
};
/*time complexity: O(logn), space complexity: O(logn)*/