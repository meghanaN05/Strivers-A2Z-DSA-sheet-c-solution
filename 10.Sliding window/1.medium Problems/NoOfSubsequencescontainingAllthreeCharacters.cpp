#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int l = 0;
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
      mp[s[i] - 'a']++;
      while (mp.size() == 3)
      {
        ans += s.size() - i;
        mp[s[l] - 'a']--;
        if (mp[s[l] - 'a'] == 0)
          mp.erase(s[l] - 'a');
        l++;
      }
    }
    return ans;
  }
};