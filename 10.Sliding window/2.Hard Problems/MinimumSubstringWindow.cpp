#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string minWindow(string s, string t)
  {
    if (s.size() == 0 || t.size() == 0)
      return "";
    vector<int> freq(128, 0);
    for (int i = 0; i < t.size(); i++)
      freq[t[i]]++;
    int l = 0;
    int start = 0;
    int mini = INT_MAX;
    int count = t.size();
    for (int r = 0; r < s.size(); r++)
    {
      if (freq[s[r]] > 0)
        count--;
      freq[s[r]]--;
      while (count == 0)
      {
        if (r - l + 1 < mini)
        {
          mini = r - l + 1;
          start = l;
        }
        freq[s[l]]++;
        if (freq[s[l]] > 0)
          count++;
        l++;
      }
    }
    if (mini == INT_MAX)
      return "";
    return s.substr(start, mini);
  }
};