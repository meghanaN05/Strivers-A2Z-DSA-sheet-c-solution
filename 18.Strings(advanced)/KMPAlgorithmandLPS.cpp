#include <bits/stdc++.h>
using namespace std;
// Build LPS array
vector<int> buildLPS(string pattern)
{
  int m = pattern.size();
  vector<int> lps(m, 0);
  int len = 0;
  int i = 1;
  while (i < m)
  {
    if (pattern[i] == pattern[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = lps[len - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}
// KMP Search
void KMP(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  vector<int> lps = buildLPS(pattern);
  int i = 0; // text pointer
  int j = 0; // pattern pointer
  while (i < n)
  {
    // Characters match
    if (text[i] == pattern[j])
    {
      i++;
      j++;
    }
    // Pattern completely matched
    if (j == m)
    {
      cout << "Pattern found at index "
           << i - j << endl;
      // Continue searching
      j = lps[j - 1];
    }
    // Characters don't match
    else if (i < n && text[i] != pattern[j])
    {
      if (j != 0)
      {
        j = lps[j - 1];
      }
      else
      {
        i++;
      }
    }
  }
}
int main()
{

  string text = "aabaacaadaabaaba";
  string pattern = "aaba";

  KMP(text, pattern);

  return 0;
}
/*time complexity:O(n+m)*/