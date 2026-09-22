#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // if you want to perform left rotation of the array by k steps then perform
  // 1)Reverse the first k elements.
  // 2)Reverse the remaining n-k elements.
  // 3)Reverse the entire array.
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};