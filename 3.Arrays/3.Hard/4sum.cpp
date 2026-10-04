#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // tc:O(n^2)
  // sc:O(1)
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < n; j++)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int l = j + 1, r = n - 1;
        long long t = 1LL * target - nums[i] - nums[j];
        while (l < r)
        {
          long long sum = 1LL * nums[l] + nums[r];
          if (sum == t)
          {
            ans.push_back({nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1])
              l++;
            while (l < r && nums[r] == nums[r - 1])
              r--;
            l++;
            r--;
          }
          else if (sum < t)
            l++;
          else
            r--;
        }
      }
    }
    return ans;
  }
};