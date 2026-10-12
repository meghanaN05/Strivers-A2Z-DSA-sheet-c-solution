#include <bits/stdc++.h>
using namespace std;
// o(n) solution
class Solution
{
public:
  int lowerBound(vector<int> &arr, int target)
  {
    // code here
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] >= target)
      {
        return i;
      }
    }
    return arr.size();
  }
};
// 0(logn) solution
class Solution
{
public:
  int lowerBound(vector<int> &arr, int target)
  {
    int low = 0, high = arr.size();

    while (low < high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] < target)
      {
        low = mid + 1;
      }
      else
      {
        high = mid;
      }
    }

    return low;
  }
};
// alternative approach using STL
class Solution
{
public:
  int lowerBound(vector<int> &arr, int target)
  {
    auto it = lower_bound(arr.begin(), arr.end(), target);
    return distance(arr.begin(), it);
  }
};