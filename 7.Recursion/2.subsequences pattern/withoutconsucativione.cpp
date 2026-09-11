#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int solve(int n, string curr, int last)
  {
    if (curr.size() == n)
    {
      return 1;
    }
    int c1 = 0;
    if (last != 1)
      c1 = solve(n, curr + '1', 1);
    int c2 = solve(n, curr + '0', 0);
    return c1 + c2;
  }
  int countStrings(int n)
  {

    return solve(n, "", 0);
  }
};
/*time complexity: O(2^n) space complexity: O(n)*/
/*optimized solution*/
class Solution
{
public:
  int countStrings(int n)
  {
    if (n == 1)
      return 2;
    int a = 2, b = 3;
    for (int i = 3; i <= n; i++)
    {
      int c = a + b;
      a = b;
      b = c;
    }

    return b;
  }
};
/*time complexity: O(n) space complexity: O(1)*/