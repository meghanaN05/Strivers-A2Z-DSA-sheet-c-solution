#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s)
{
  int n = s.size();
  vector<int> z(n, 0);

  int l = 0, r = 0;

  for (int i = 1; i < n; i++)
  {

    if (i <= r)
    {
      z[i] = min(r - i + 1, z[i - l]);
    }

    while (i + z[i] < n &&
           s[z[i]] == s[i + z[i]])
    {
      z[i]++;
    }

    if (i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}
vector<int> search(string text, string pattern)
{

  string s = pattern + "$" + text;

  vector<int> z = z_function(s);

  vector<int> ans;

  int m = pattern.size();

  for (int i = 0; i < s.size(); i++)
  {

    if (z[i] == m)
    {
      ans.push_back(i - m - 1);
    }
  }

  return ans;
}
/*time complexity: O(n+m), space complexity: O(n+m) where n is the length of the text and m is the length of the pattern*/