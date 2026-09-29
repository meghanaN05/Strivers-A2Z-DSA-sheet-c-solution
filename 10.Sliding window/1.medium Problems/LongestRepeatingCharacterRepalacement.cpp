#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int l = 0;
    int maxi = 0;
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
      mp[s[i] - 'A']++;
      maxi = max(maxi, mp[s[i] - 'A']);
      while (i - l + 1 - maxi > k)
      {
        mp[s[l] - 'A']--;
        l++;
      }
      ans = max(ans, i - l + 1);
    }
    return ans;
  }
};