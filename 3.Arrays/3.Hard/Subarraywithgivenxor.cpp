#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  long subarrayXor(vector<int> &arr, int k)
  {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int cnt = 0;
    int xori = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      xori = xori ^ arr[i];
      int target = xori ^ k;
      if (mp.find(target) != mp.end())
      {
        cnt += mp[target];
      }
      mp[xori]++;
    }
    return cnt;
  }
};