#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // optimal
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> mp;
    vector<int> vis(256, 0);
    for (int i = 0; i < s.size(); i++)
    {
      if (mp.find(s[i]) == mp.end())
      {
        if (vis[t[i]])
          return false;
        mp[s[i]] = t[i];
        vis[t[i]] = 1;
      }
      else
      {
        if (mp[s[i]] != t[i])
          return false;
      }
    }
    return true;
  }
};