
#include <bits/stdc++.h>
using namespace std;
char ShortestPalindrome(string s)
{
  int n = s.length();
  char ans = s[0];
  for (int i = 1; i < n; i++)
  {
    ans = min(ans, s[i]);
  }

  return ans;
}
