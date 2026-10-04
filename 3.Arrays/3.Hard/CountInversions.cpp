#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void merge(int low, int mid, int high, vector<int> &nums)
  {
    vector<int> temp;
    int l = low;
    int r = mid + 1;
    while (l <= mid && r <= high)
    {
      if (nums[l] <= nums[r])
      {
        temp.push_back(nums[l]);
        l++;
      }
      else
      {
        temp.push_back(nums[r]);
        r++;
      }
    }
    while (l <= mid)
    {
      temp.push_back(nums[l]);
      l++;
    }
    while (r <= high)
    {
      temp.push_back(nums[r]);
      r++;
    }
    for (int i = low; i <= high; i++)
    {
      nums[i] = temp[i - low];
    }
  }
  int Rev(int low, int mid, int high, vector<int> &nums)
  {
    int r = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
      while (r <= high && (long long)nums[i] > nums[r])
        r++;
      cnt += r - (mid + 1);
    }
    return cnt;
  }
  int mergesort(int low, int high, vector<int> &nums)
  {
    if (low >= high)
      return 0;
    int mid = low + (high - low) / 2;
    int cnt = 0;
    cnt += mergesort(low, mid, nums);
    cnt += mergesort(mid + 1, high, nums);
    cnt += Rev(low, mid, high, nums);
    merge(low, mid, high, nums);
    return cnt;
  }
  int countInversions(vector<int> &nums)
  {
    return mergesort(0, nums.size() - 1, nums);
  }
};
