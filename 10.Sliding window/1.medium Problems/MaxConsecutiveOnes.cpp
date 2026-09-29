#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int l = 0;
    int zero = 0;
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
        zero++;
      while (zero > k)
      {
        if (nums[l] == 0)
          zero--;
        l++;
      }
      maxi = max(maxi, i - l + 1);
    }

    return maxi;
  }
};