#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxDepth(string s)
  {
    int open = 0;
    int maxi = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
        open++;
      if (s[i] == ')')
        open--;
      maxi = max(maxi, open);
    }
    return maxi;
  }
};