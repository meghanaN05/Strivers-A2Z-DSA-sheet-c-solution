#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  multiset<int> low, high;
  // tc:o(nlogk) sc:o(k)
  void rebalance()
  {
    if (low.size() > high.size() + 1)
    {
      high.insert(*low.rbegin());
      low.erase(prev(low.end()));
    }
    if (high.size() > low.size())
    {
      low.insert(*high.begin());
      high.erase(high.begin());
    }
  }
  double getMedian(int k)
  {
    if (k % 2 == 1)
      return *low.rbegin();
    return ((double)*low.rbegin() + *high.begin()) / 2.0;
  }
  vector<double> medianSlidingWindow(vector<int> &nums, int k)
  {
    vector<double> res;
    for (int i = 0; i < nums.size(); i++)
    {
      if (low.empty() || *low.rbegin() > nums[i])
        low.insert(nums[i]);
      else
        high.insert(nums[i]);
      rebalance();
      if (i >= k)
      {
        if (low.find(nums[i - k]) != low.end())
          low.erase(low.find(nums[i - k]));
        else
          high.erase(high.find(nums[i - k]));
      }
      rebalance();
      if (i >= k - 1)
      {
        res.push_back(getMedian(k));
      }
    }
    return res;
  }
};