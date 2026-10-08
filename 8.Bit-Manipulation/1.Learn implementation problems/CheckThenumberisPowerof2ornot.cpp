#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isPowerofTwo(int n)
  {
    if (n == 1)
      return true;
    if (n <= 0 || n % 2 != 0)
    {
      return false;
    }
    return isPowerofTwo(n / 2);

    //  return num > 0 && (num & (num - 1)) == 0;
  }
};