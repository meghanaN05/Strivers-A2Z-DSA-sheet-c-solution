#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string minWindow(string &s, string &p)
  {
    int n = s.size(), m = p.size();
    int minLen = INT_MAX;
    int startIdx = -1;
    int i = 0, j = 0;
    while (i < n)
    {
      if (s[i] == p[j])
      {
        j++;
      }
      if (j == m)
      {
        int end = i;
        j--;
        while (j >= 0)
        {
          if (s[i] == p[j])
          {
            j--;
          }
          i--;
        }
        i++;
        j = 0;
        if (end - i + 1 < minLen)
        {
          minLen = end - i + 1;
          startIdx = i;
        }
      }
      i++;
    }
    return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
  }
};
