#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{
  vector<int> freq(26, 0);
  int maxi = 0;
  int l = 0;
  int distinctCount = 0;

  for (int r = 0; r < str.size(); r++)
  {
    // If character appears for the first time in current window
    if (freq[str[r] - 'a'] == 0)
    {
      distinctCount++;
    }
    freq[str[r] - 'a']++;

    // Shrink window if distinct characters exceed k
    while (distinctCount > k)
    {
      freq[str[l] - 'a']--;
      if (freq[str[l] - 'a'] == 0)
      {
        distinctCount--;
      }
      l++;
    }

    maxi = max(maxi, r - l + 1);
  }

  return maxi;
}