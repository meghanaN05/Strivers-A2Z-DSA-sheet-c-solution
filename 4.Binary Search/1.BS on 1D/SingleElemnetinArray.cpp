#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (mid % 2 == 1)
      {
        mid--; // make it even
      }
      if (nums[mid] != nums[mid + 1]) // pair broke hence it must be before mid
        r = mid;
      else
        l = mid + 2;
    }
    return nums[l];
  }
};