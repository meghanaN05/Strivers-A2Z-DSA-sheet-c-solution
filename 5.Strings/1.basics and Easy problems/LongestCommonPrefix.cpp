#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // brute force approach
  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.empty())
      return "";
    string s = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
      char c = strs[0][i];
      for (int j = 1; j < strs.size(); j++)
      {
        if (i >= strs[j].size() || strs[j][i] != c)
        {
          return s;
        }
      }
      s += c;
    }
    return s;
  }
};
class Solution
{
public:
  // simplest approach
  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.empty())
      return "";
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string first = strs[0];
    string last = strs[n - 1];
    int i = 0;
    while (i < first.size() && i < last.size() && first[i] == last[i])
      i++;
    return first.substr(0, i);
  }
};
// tc:O(nlogn) && sc:O(1)
