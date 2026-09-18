#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int curr = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      if (i > curr)
        return false;
      curr = max(curr, i + nums[i]);
    }
    return true;
  }
};
/*time complexity:O(n) && space complexity:O(1)*/