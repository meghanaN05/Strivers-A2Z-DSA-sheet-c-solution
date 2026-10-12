#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int findCeil(vector<int> &arr, int target)
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
    if (low == arr.size())
      return -1;

    return low;
  }
};