#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool possible(vector<int> &nums, int mid, int threshold)
  {
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      result += ceil((double)nums[i] / mid);
    }
    return result <= threshold;
  }
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    int low = 1;
    int high = 1e7;
    int ans = 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (possible(nums, mid, threshold))
      {
        ans = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return ans;
  }
};