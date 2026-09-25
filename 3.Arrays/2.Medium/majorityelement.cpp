#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    for (int x : nums)
    {
      mp[x]++;
    }
    int n = nums.size();
    for (auto it : mp)
    {
      if (it.second > n / 2)
        return it.first;
    }
    return -1;
  }
};