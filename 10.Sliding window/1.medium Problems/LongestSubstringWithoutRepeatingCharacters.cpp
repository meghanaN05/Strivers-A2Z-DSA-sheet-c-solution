#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int l = 0;
    int maxi = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
      mp[s[i] - 'a']++;
      while (mp[s[i] - 'a'] > 1)
      {
        mp[s[l] - 'a']--;
        l++;
      }
      maxi = max(maxi, i - l + 1);
    }
    return maxi;
  }
};