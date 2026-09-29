#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string reverseWords(string s)
  {
    string ans;
    int i = s.size() - 1;
    while (i >= 0)
    {
      while (i >= 0 && s[i] == ' ')
        i--;
      if (i < 0)
        break;
      int j = i;
      while (i >= 0 && s[i] != ' ')
        i--;
      ans += s.substr(i + 1, j - i);
      while (i >= 0 && s[i] == ' ')
        i--;
      if (i >= 0)
        ans += ' ';
    }
    return ans;
  }
};
// better approch
class Solution
{
public:
  string reverseWords(string s)
  {
    stringstream ss(s);
    string word, ans = "";
    while (ss >> word)
    {
      if (!ans.empty())
      {
        ans = word + " " + ans;
      }
      else
      {
        ans = word;
      }
    }
    return ans;
  }
};
/*tc:o(n) && sc:o(n)*/