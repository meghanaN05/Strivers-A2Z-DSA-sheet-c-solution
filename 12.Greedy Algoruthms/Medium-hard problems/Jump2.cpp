#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int cnt = 0;
    int end = 0;
    int curr = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      curr = max(curr, i + nums[i]);
      if (i == end)
      {
        cnt++;
        end = curr;
      }
    }
    return cnt;
  }
};