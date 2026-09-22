#include <bits/stdc++.h>
using namespace std;
void movezero(vector<int> &nums)
{
  int zero = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != 0)
    {
      swap(nums[i], nums[zero]);
      zero++;
    }
  }
};
/*tc:0(n) sc:O(1)*/