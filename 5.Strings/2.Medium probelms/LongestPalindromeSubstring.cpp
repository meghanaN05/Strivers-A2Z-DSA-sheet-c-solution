#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  pair<int, int> expand(string &s, int l, int r)
  {
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
      l--;
      r++;
    }
    return {l + 1, r - 1};
  }

  string longestPalindrome(string s)
  {
    int n = s.size();
    int bestL = 0, bestR = 0;
    for (int i = 0; i < n; i++)
    {
      auto [l1, r1] = expand(s, i, i);
      auto [l2, r2] = expand(s, i, i + 1);
      if (r1 - l1 > bestR - bestL)
      {
        bestL = l1;
        bestR = r1;
      }
      if (r2 - l2 > bestR - bestL)
      {
        bestL = l2;
        bestR = r2;
      }
    }
    return s.substr(bestL, bestR - bestL + 1);
  }
};
// This code finds the longest palindromic substring in a given string using the expand around center approach. It checks for both odd and even length palindromes by expanding from each character and its adjacent character. The time complexity is O(n^2) and the space complexity is O(1).