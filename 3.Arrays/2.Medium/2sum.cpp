#include <bits/stdc++.h>
using namespace std;
// map based appraoch
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
      int complement = target - nums[i];
      if (mp.find(complement) != mp.end())
      {
        return {mp[complement], i};
      }
      mp[nums[i]] = i;
    }
    return {-1, -1};
  }
};
// two pointers approach
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
      arr[i] = {nums[i], i};
    }
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
      int sum = arr[left].first + arr[right].first;
      if (sum == target)
      {
        return {arr[left].second, arr[right].second};
      }
      else if (sum < target)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
    return {-1, -1};
  }
};
