#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int longestKSubstr(string &s, int k)
  {
    int l = 0;
    int maxi = -1;
    unordered_map<char, int> freq;

    for (int i = 0; i < s.size(); i++)
    {
      freq[s[i]]++;

      while (freq.size() > k)
      {
        freq[s[l]]--;
        if (freq[s[l]] == 0)
          freq.erase(s[l]);
        l++;
      }

      if (freq.size() == k)
        maxi = max(maxi, i - l + 1);
    }

    return maxi;
  }
};