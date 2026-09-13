#include <bits/stdc++.h>
using namespace std;
vector<int> robinkarp(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  const long long Base = 256;
  const long long MOD = 169 + 7;
  long long patterHash = 0;
  long long textHash = 0;
  long long power = 1;
  for (int i = 0; i < m - 1; i++)
  {
    power = (power * Base) % MOD;
  }
  for (int i = 0; i < m; i++)
  {
    patterHash = (patterHash * Base + pattern[i]) % MOD;
    textHash = (textHash * Base + text[i]) % MOD;
  }
  for (int i = 0; i <= n - m; i++)
  {
    if (patterHash == textHash)
    {
      text.substr(i, m);
      if (text.substr(i, m) == pattern)
      {
        ans.push_back(i);
      }
    }
    if (i < n - m)
    {
      textHash = (textHash - ((text[i] * power) % MOD) + MOD) % MOD;
      textHash = (textHash * Base + text[i + m]) % MOD;
    }
  }
  return ans;
};
/*time complexity: O(n+m), space complexity: O(1) where n is the length of the text and m is the length of the pattern*/