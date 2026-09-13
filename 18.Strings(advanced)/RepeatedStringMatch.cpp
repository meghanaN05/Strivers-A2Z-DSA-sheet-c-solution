#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // can also solve this using robin-karp-KMP algorithm
  int repeatedStringMatch(string a, string b)
  {
    string res = a;
    int cnt = 1;
    while (res.size() < b.size())
    {
      res += a;
      cnt++;
    }
    if (res.find(b) != string::npos)
    {
      return cnt;
    }
    res += a;
    cnt++;
    if (res.find(b) != string::npos)
    {
      return cnt;
    }
    return -1;
  }
};