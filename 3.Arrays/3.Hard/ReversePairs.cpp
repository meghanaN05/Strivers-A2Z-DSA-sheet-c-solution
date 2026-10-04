#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // mergesort approach(used for count-inversions gfg problem and reverse pairs)
  void merge(int low, int mid, int high, vector<int> &nums)
  {
    int l = low, r = mid + 1;
    vector<int> temp;
    while (l <= mid && r <= high)
    {
      if (nums[l] <= nums[r])
        temp.push_back(nums[l++]);
      else
        temp.push_back(nums[r++]);
    }
    while (l <= mid)
      temp.push_back(nums[l++]);
    while (r <= high)
      temp.push_back(nums[r++]);
    for (int i = low; i <= high; i++)
      nums[i] = temp[i - low];
  }
  int cp(int low, int mid, int high, vector<int> &nums)
  {
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
      while (right <= high && (long long)nums[i] > 2LL * nums[right])
        right++;
      cnt += (right - (mid + 1));
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
    cnt += cp(low, mid, high, nums);
    merge(low, mid, high, nums);
    return cnt;
  }
  int reversePairs(vector<int> &nums)
  {
    return mergesort(0, nums.size() - 1, nums);
  }
};