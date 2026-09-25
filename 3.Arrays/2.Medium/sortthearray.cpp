#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();
    while (n > 0)
    {
      for (int i = 0; i < nums.size() - 1; i++)
      {
        if (nums[i] > nums[i + 1])
          swap(nums[i], nums[i + 1]);
      }
      n--;
    }
  }
};
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
      if (nums[mid] == 0)
      {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
      }
      else if (nums[mid] == 1)
      {
        mid++;
      }
      else
      {
        swap(nums[mid], nums[high]);
        high--;
      }
    }
  }
};