#include <bits/stdc++.h>
using namespace std;
// o(n) solution
class Solution
{
public:
  int findKRotation(vector<int> &arr)
  {
    // Code Here

    int cnt = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
      if (arr[i] < arr[i + 1])
      {
        cnt++;
      }
      else
      {
        return cnt + 1;
      }
    }
    if (cnt == arr.size() - 1)
      return 0;
  }
};
// optitmeazed solution using binary search
class Solution
{
public:
  int findKRotation(vector<int> &arr)
  {
    // Code Here
    int low = 0;
    int high = arr.size() - 1;
    while (low < high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] > arr[high])
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