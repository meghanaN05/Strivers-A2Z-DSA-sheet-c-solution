#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int countFreq(vector<int> &nums, int x)
  {
    // code here
    auto lb = lower_bound(nums.begin(), nums.end(), x);
    auto ub = upper_bound(nums.begin(), nums.end(), x);
    if (lb == nums.end() || *lb != x)
      return 0;
    int first = lb - nums.begin();
    int last = ub - nums.begin() - 1;
    return last - first + 1;
  }
};
