#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string removeOuterParentheses(string s)
  {
    int open = 0;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        open++;
        if (open > 1)
          res += s[i];
      }
      if (s[i] == ')')
      {
        open--;
        if (open > 0)
          res += s[i];
      }
    }

    return res;
  }
};