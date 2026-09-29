#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int solve(vector<int> &nums, int k)
  {
    int l = 0;
    int maxi = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
      mp[nums[i]]++;
      while (mp.size() > k)
      {
        mp[nums[l]]--;
        if (mp[nums[l]] == 0)
          mp.erase(nums[l]);
        l++;
      }
      maxi += i - l + 1;
    }
    return maxi;
  }
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    return solve(nums, k) - solve(nums, k - 1);
  }
};
// tc:O(n) && sc:O(n)
