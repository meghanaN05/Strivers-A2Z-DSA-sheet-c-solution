#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    int l = 0;
    int maxi = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < fruits.size(); i++)
    {
      mp[fruits[i]]++;
      while (mp.size() > 2)
      {
        mp[fruits[l]]--;
        if (mp[fruits[l]] == 0)
          mp.erase(fruits[l]);
        l++;
      }
      maxi = max(maxi, i - l + 1);
    }
    return maxi;
  }
};