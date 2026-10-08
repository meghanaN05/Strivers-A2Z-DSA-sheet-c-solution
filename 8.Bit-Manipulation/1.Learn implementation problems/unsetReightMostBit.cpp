#include <bits/stdc++.h>
using namespace std;
int unsetRightMostBit(int l, int r)
{
  int xured = l ^ r;
  int msb = 0;

  // Find the position of the most significant set bit
  while (xured > 0)
  {
    msb = (msb << 1) | 1;
    xured >>= 1;
  }

  return msb;
}
// set the rightmost unset bit of the number
class Solution
{
public:
  int setBit(int n)
  {
    return n | (n + 1);
  }
};