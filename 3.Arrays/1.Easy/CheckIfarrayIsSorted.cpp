#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int count = 0, n = nums.size();
    for (int i = 0; i < n; i++)
      if (nums[i] > nums[(i + 1) % n] && ++count > 1)
        return false;
    return true;
  }
};
// another approach
class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int cnt = 0;
    int n = nums.size();
    if (nums[n - 1] > nums[0])
      cnt++;
    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] > nums[i + 1])
        cnt++;
    }
    return cnt <= 1;
  }
};