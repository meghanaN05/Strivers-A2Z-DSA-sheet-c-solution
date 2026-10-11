#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // bit manipulation approach
  vector<int> singleNumber(vector<int> &nums)
  {
    int xori = 0;
    for (int x : nums)
      xori = xori ^ x;
    // int diff = xori& ~(xori - 1);
    unsigned int diff = (unsigned int)xori & (-(unsigned int)xori);
    int a = 0, b = 0;
    for (int x : nums)
    {
      if (x & diff)
        a = a ^ x;
      else
        b = b ^ x;
    }
    return {a, b};
  }
};