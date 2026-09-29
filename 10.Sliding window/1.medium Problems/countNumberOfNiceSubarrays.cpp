#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // using sliding window technique
  int solve(vector<int> &nums, int k)
  {
    if (k < 0)
      return 0;
    int odd = 0;
    int maxi = 0;
    int l = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] % 2 == 1)
        odd++;
      while (odd > k)
      {
        if (nums[l] % 2 == 1)
          odd--;
        l++;
      }
      maxi += i - l + 1;
    }
    return maxi;
  }
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    return solve(nums, k) - solve(nums, k - 1);
  }
};