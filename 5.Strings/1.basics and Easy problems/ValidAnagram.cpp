#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // optimal-space is o(1)
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};
