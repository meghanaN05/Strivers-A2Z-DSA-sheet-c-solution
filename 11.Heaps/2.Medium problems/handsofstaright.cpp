#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isStraightHand(vector<int> &arr, int m)
  {
    // code here
    int n = arr.size();
    if (n % m != 0)
      return false;
    map<int, int> mp;
    for (auto x : arr)
      mp[x]++;
    while (!mp.empty())
    {
      auto start = mp.begin()->first;
      for (int i = 0; i < m; i++)
      {
        auto card = i + start;
        if (mp[card] == 0)
          return false;
        mp[card]--;
        if (mp[card] == 0)
          mp.erase(card);
      }
    }
    return true;
  }
};