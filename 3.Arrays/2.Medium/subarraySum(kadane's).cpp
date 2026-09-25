#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // kadane algorithm
  int maxSubArray(vector<int> &nums)
  {
    int maxi = INT_MIN;
    int curr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      curr = max(nums[i], curr + nums[i]);
      maxi = max(maxi, curr);
    }
    return maxi;
  }
};