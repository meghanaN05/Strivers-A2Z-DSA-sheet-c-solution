#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int beautySum(string s)
  {
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
      vector<int> freq(26, 0);
      for (int j = i; j < s.size(); j++)
      {
        freq[s[j] - 'a']++;
        int mn = INT_MAX, mx = INT_MIN;
        for (int k = 0; k < 26; k++)
        {
          if (freq[k] > 0)
          {
            mn = min(mn, freq[k]);
            mx = max(mx, freq[k]);
          }
        }
        sum += mx - mn;
      }
    }
    return sum;
  }
};