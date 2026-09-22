#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      ans += mp[sum - k];
      if (sum == k)
        ans++;
      mp[sum]++;
    }
    return ans;
  }
};