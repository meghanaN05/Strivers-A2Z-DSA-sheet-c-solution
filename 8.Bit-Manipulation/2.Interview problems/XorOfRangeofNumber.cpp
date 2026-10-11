#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int xorUpto(int x)
  {
    if (x % 4 == 0)
      return x;
    else if (x % 4 == 1)
      return 1;
    else if (x % 4 == 2)
      return x + 1;
    else
      return 0;
  }

  int findXOR(int l, int r)
  {
    return xorUpto(r) ^ xorUpto(l - 1);
  }
};