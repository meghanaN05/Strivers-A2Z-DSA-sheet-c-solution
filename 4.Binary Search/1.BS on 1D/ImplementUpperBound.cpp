#include <bits/stdc++.h>
using namespace std;
// o(n)  solution
class Solution
{
public:
  int upperBound(vector<int> &arr, int target)
  {
    // code here
    for (int i = 0; i < arr.size(); i++)
    {
      if (target < arr[i])
        return i;
    }
    return arr.size();
  }
};

class Solution
{
public:
  int upperBound(vector<int> &arr, int target)
  {
    int low = 0, high = arr.size();

    while (low < high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] <= target)
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
// Alternative approach using STL
class Solution
{
public:
  int upperBound(vector<int> &arr, int target)
  {
    auto it = upper_bound(arr.begin(), arr.end(), target);
    return distance(arr.begin(), it);
  }
};