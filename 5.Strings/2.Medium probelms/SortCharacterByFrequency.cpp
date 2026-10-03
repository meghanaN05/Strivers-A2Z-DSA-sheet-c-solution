#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string frequencySort(string s)
  {
    unordered_map<char, int> mp;
    for (char c : s)
      mp[c]++;
    vector<pair<char, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second > b.second; });
    string ans;
    for (auto &p : v)
    {
      ans.append(p.second, p.first);
    }
    return ans;
  }
};