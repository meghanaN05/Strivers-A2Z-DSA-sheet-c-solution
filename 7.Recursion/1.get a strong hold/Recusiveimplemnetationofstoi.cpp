#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int solve(string &s, int i, long long ans, int sign)
  {
    if (s.size() == i || !isdigit(s[i]))
      return sign * ans;
    ans = ans * 10 + (s[i] - '0');
    if (sign == 1 && ans > INT_MAX)
      return INT_MAX;
    if (sign == -1 && -ans < INT_MIN)
      return INT_MIN;
    return solve(s, i + 1, ans, sign);
  }
  int myAtoi(string s)
  {
    int n = s.size();
    int i = 0;
    int sign = 1;
    while (i < n && s[i] == ' ')
      i++;
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
      if (s[i] == '-')
        sign = -1;
      i++;
    }
    return solve(s, i, 0, sign);
  }
};
/*time complexity: O(n), space complexity: O(n)*/