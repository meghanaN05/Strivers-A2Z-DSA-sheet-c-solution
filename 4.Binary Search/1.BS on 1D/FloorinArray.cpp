#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int floor(vector<int> &arr, int target)
  {
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target)
        return mid;
      else if (arr[mid] < target)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return high;
  }
};